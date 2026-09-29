# ESP32 / IoT Monitoring

## Controller

ESP32-WROOM-32 or equivalent ESP32 platform.

## Parameters

The system is intended to monitor:
- solar voltage
- solar current
- wind voltage
- wind current
- battery voltage
- battery state
- rotor RPM
- wind speed
- irradiance
- temperature/environmental parameters where sensors are installed

## Communication

The project documentation proposes:
- Wi-Fi
- MQTT
- cloud dashboard
- local Node-RED interface

Possible dashboard platforms:
- ThingsBoard
- Blynk
- Node-RED

Use only the platform actually implemented in the prototype.

## Dashboard evidence

Every displayed value should have:
- parameter name
- unit
- timestamp
- source/sensor
- measured/calculated/simulated status

Do not display theoretical values under a "LIVE" or "MEASURED" label.
