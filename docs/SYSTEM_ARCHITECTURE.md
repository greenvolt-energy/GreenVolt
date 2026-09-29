# System Architecture

## Energy flow

### Solar path

```text
Solar PV
  ↓
PV Protection
  ↓
Solar MPPT / DC-DC Regulation
  ↓
Shared DC Bus
```

### Wind path

```text
Wind
  ↓
AeroLeaf VAWT
  ↓
Shaft
  ↓
Low-KV BLDC / PM Generator(s)
  ↓
3-Phase Rectification
  ↓
Wind Power Conditioning / MPPT
  ↓
Shared DC Bus
```

### Storage and load

```text
Shared DC Bus
   ├── Battery + BMS
   ├── Supercapacitor Buffer
   ├── DC Loads
   └── Optional Inverter
```

## Monitoring

```text
Voltage Sensors
Current Sensors
RPM Sensor
Wind Sensor
Irradiance / Environmental Sensors
        ↓
      ESP32
        ↓
Wi-Fi / MQTT
        ↓
Dashboard / Node-RED / Cloud
```

## Protection

```text
Source protection
   ↓
Fuses / DC isolators / reverse-polarity protection
   ↓
Bus protection
   ↓
Wind braking / dump-load provision
   ↓
Emergency shutdown
```
