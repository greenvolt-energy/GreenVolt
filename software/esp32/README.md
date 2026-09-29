# ESP32 Firmware

Purpose:
- Read voltage/current sensors
- Read RPM sensor
- Read environmental sensors where available
- Calculate electrical power
- Log telemetry
- Publish data over Wi-Fi/MQTT
- Support dashboard visualization

## Required before public release

Remove:
- Wi-Fi passwords
- MQTT credentials
- API tokens
- cloud secrets

Use environment/configuration files that are excluded from Git.

## Firmware evidence

Include:
- board model
- sensor model
- calibration constants
- sampling interval
- communication protocol
- data format


## Security

Credentials are intentionally replaced with placeholders in `code.ino`. Before running locally, supply your own Wi-Fi and Blynk credentials. Never commit real passwords, authentication tokens, or private API keys.
