#define BLYNK_TEMPLATE_ID "YOUR_BLYNK_TEMPLATE_ID"
#define BLYNK_TEMPLATE_NAME "YOUR_BLYNK_TEMPLATE_NAME"
#define BLYNK_AUTH_TOKEN "YOUR_BLYNK_AUTH_TOKEN"

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <HTTPClient.h>

// --- WiFi Credentials ---
char ssid[] = "YOUR_WIFI_SSID";
char pass[] = "YOUR_WIFI_PASSWORD";

// --- Google Sheets Config ---
const char* GOOGLE_SCRIPT_URL = "https://script.google.com/macros/s/YOUR_SCRIPT_ID/exec";

// --- OLED & Pin Config ---
#define OLED_ADDR 0x3C
Adafruit_SSD1306 display(128, 64, &Wire, -1);

#define BATTERY_ADC_PIN 34 
#define BUS_ADC_PIN     35 
#define SOLAR_BUS_PIN   32

// --- Calibration Factors ---
const float BAT_CAL_FACTOR = 3.89/2200; 
const float BUS_CAL_FACTOR = 1.80/2055; 
const float SOLAR_BUS_FACTOR = 1.80/2055;

BlynkTimer timer;
bool blynkConnected = false;

// --- Calculation Functions ---
float readADCVoltage(int adcPin, float calFactor) {
    long raw_value = 0;
    for(int i=0; i<64; i++) { 
        raw_value += analogRead(adcPin); 
        delay(1); 
    }
    return ((float)raw_value / 64.0) * calFactor;
}

float getBatterySOC(float voltage) {
    if (voltage >= 4.20) return 100.0;
    if (voltage >= 4.00) return 90.0;
    if (voltage >= 3.85) return 75.0;
    if (voltage >= 3.70) return 50.0;
    if (voltage >= 3.50) return 20.0;
    if (voltage >= 3.30) return 5.0;
    return 0.0;
}

// --- Google Sheets Logging Function ---
void logToGoogleSheets(float solarV, float windV, float batteryV, const char* mode) {
    if (WiFi.status() == WL_CONNECTED) {
        HTTPClient http;

        String url = String(GOOGLE_SCRIPT_URL);
        url += "?solar=" + String(solarV, 2);
        url += "&wind=" + String(windV, 2);
        url += "&battery=" + String(batteryV, 2);
        url += "&mode=" + String(mode);

        http.begin(url);
        http.GET();
        http.end();
    }
}

// --- Function to Send Data ---
void sendSensorData() {
    float batteryVoltage = readADCVoltage(BATTERY_ADC_PIN, BAT_CAL_FACTOR);
    float busVoltage     = readADCVoltage(BUS_ADC_PIN, BUS_CAL_FACTOR);
    float solarvoltage   = readADCVoltage(SOLAR_BUS_PIN, SOLAR_BUS_FACTOR);
    float socPercent     = getBatterySOC(batteryVoltage);

    // Update Local OLED
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    
    display.setCursor(0, 0);
    display.print("TURBINE: ");
    display.print(busVoltage, 2);
    display.print("V");

    display.setCursor(0, 16);
    display.print("SOLAR: ");
    display.print(solarvoltage, 2);
    display.print("V");
    
    display.setCursor(0, 32);
    display.print("BATTERY: ");
    display.print(socPercent, 0);
    display.print("%");
    
    display.setCursor(0, 48);
    display.print("BAT V: ");
    display.print(batteryVoltage, 2);
    display.print("V");
    
    display.display();
    
    // Send to Blynk only if connected
    if(blynkConnected) {
        Blynk.virtualWrite(V35, busVoltage);
        Blynk.virtualWrite(V34, batteryVoltage);
        Blynk.virtualWrite(V1, socPercent);
        Blynk.virtualWrite(V32, solarvoltage);
    }
    
    // Send to Google Sheets
    logToGoogleSheets(solarvoltage, busVoltage, batteryVoltage, "HYBRID");
}

// --- Display Energy Tree Logo ---
void showLogo() {
    display.clearDisplay();
    display.fillRect(58, 40, 12, 24, SSD1306_WHITE);
    display.fillCircle(64, 30, 18, SSD1306_WHITE);
    display.fillCircle(50, 35, 12, SSD1306_WHITE);
    display.fillCircle(78, 35, 12, SSD1306_WHITE);
    
    display.setTextSize(2);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(10, 10);
    display.print("ENERGY");
    display.setCursor(25, 50);
    display.print("TREE");
    display.display();
    delay(2000);
}

// --- WiFi Connection with Timeout ---
bool connectWiFiWithTimeout() {
    display.clearDisplay();
    display.setTextSize(1);
    display.setCursor(0, 20);
    display.print("Connecting WiFi...");
    display.display();
    
    WiFi.begin(ssid, pass);
    unsigned long startTime = millis();
    
    while (WiFi.status() != WL_CONNECTED) {
        if (millis() - startTime > 5000) {
            display.clearDisplay();
            display.setCursor(0, 20);
            display.print("WiFi Timeout!");
            display.setCursor(0, 35);
            display.print("Running Offline");
            display.display();
            delay(1500);
            return false;
        }
        delay(100);
    }
    
    display.clearDisplay();
    display.setCursor(0, 20);
    display.print("WiFi Connected!");
    display.display();
    delay(1000);
    return true;
}

void setup() {
    Serial.begin(115200);
    
    // Initialize OLED
    if(!display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR)) { 
        Serial.println("OLED init failed!");
        for(;;); 
    }
    
    // Show Logo
    showLogo();
    
    // Try WiFi connection
    if(connectWiFiWithTimeout()) {
        display.clearDisplay();
        display.setCursor(0, 25);
        display.print("Connecting Blynk...");
        display.display();
        
        Blynk.config(BLYNK_AUTH_TOKEN);
        if(Blynk.connect()) {
            blynkConnected = true;
            display.clearDisplay();
            display.setCursor(0, 25);
            display.print("Blynk Connected!");
            display.display();
            delay(1000);
        } else {
            display.clearDisplay();
            display.setCursor(0, 20);
            display.print("Blynk Failed!");
            display.setCursor(0, 35);
            display.print("Running Local");
            display.display();
            delay(1500);
        }
    }
    
    timer.setInterval(2000L, sendSensorData);
}

void loop() {
    if(blynkConnected) {
        Blynk.run();
    }
    timer.run();
}
*newly added spread sheet data collection*