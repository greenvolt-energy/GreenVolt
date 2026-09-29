# GREENVOLT — Hybrid Wind-Solar Energy Tree

**Smart India Hackathon 2026 | Problem Statement 26217**  
**Theme:** Renewable / Sustainable Energy  
**Category:** Hardware  
**Project:** Dual Mode Tree — Hybrid Solar–Wind Energy Generation and Monitoring System

## 1. Project Overview

GreenVolt, also referred to as the **Dual Mode Tree**, is a compact, tree-inspired hybrid renewable-energy concept that combines solar photovoltaic generation with an AeroLeaf-inspired vertical-axis wind turbine.

The system is intended to demonstrate how two naturally variable renewable sources can be integrated into a common power-management and monitoring architecture.

The project focuses on:

- Hybrid solar + wind energy harvesting
- AeroLeaf / Savonius-inspired vertical-axis wind capture
- Modular multi-generator wind architecture
- Source-specific power conditioning and MPPT
- Common DC-bus integration
- Battery energy storage
- ESP32-based monitoring
- Electrical protection and wind braking
- Modular fabrication and serviceability
- Experimental validation of actual electrical output

## 2. Problem

Solar generation is unavailable at night and decreases during cloudy conditions. Urban wind can also be low, gusty and directionally variable.

GreenVolt addresses these system-level challenges by combining solar and wind generation in one compact structure and providing monitoring, protection and modular maintenance features.

## 3. Proposed System

### Renewable sources

**Solar subsystem**
- 4 × 20 W photovoltaic panels
- Installed PV capacity: 80 W
- Modular branch-mounted arrangement

**Wind subsystem**
- AeroLeaf / Savonius-inspired VAWT
- Up to 8 low-KV BLDC/gimbal generator units
- Individual three-phase rectification
- Experimental optimization using wind speed, RPM, torque, voltage, current and power

### Monitoring

ESP32-based monitoring is intended to measure:
- Voltage
- Current
- Power
- Rotor RPM
- Battery status
- Wind speed
- Irradiance / environmental parameters where sensors are available

The planned communication architecture uses Wi-Fi with MQTT and a dashboard such as ThingsBoard, Blynk, or Node-RED.

## 4. Electrical Architecture — IMPORTANT STATUS NOTE

The current project documentation contains **legacy 24 V references**, while the latest GreenVolt presentation direction requested by the team uses a **48 V shared DC bus**.

Therefore, this repository deliberately separates:
- **Source/document-derived specifications**
- **Latest proposed architecture**
- **Measured/validated results**

Before final submission, all hardware, battery, charge-controller, protection, converter, wiring and load ratings must be verified for the selected bus voltage.

See:
`docs/ARCHITECTURE_STATUS.md`

## 5. Evidence Policy

This repository distinguishes:

- **MEASURED** — directly obtained from physical instrumentation/testing
- **CALCULATED** — obtained from equations/model assumptions
- **SIMULATED** — generated using software models
- **PLANNED** — intended future test/design
- **TARGET** — design objective, not a measured result

No calculated or target value should be presented as measured prototype performance.

## 6. Repository Structure

```text
GreenVolt-SIH-2026/
├── README.md
├── LICENSE_DECISION.md
├── .gitignore
├── docs/
│   ├── PROJECT_OVERVIEW.md
│   ├── ARCHITECTURE_STATUS.md
│   ├── SYSTEM_ARCHITECTURE.md
│   ├── TECHNICAL_APPROACH.md
│   ├── MPPT_AND_CONTROL.md
│   ├── BRAKING_AND_SAFETY.md
│   ├── IOT_MONITORING.md
│   ├── FEASIBILITY_AND_RISKS.md
│   ├── IMPACT_AND_APPLICATIONS.md
│   ├── RESEARCH_AND_PRIOR_ART.md
│   ├── VALIDATION_PLAN.md
│   └── FUTURE_SCOPE.md
├── hardware/
│   ├── BOM.csv
│   ├── COMPONENT_SELECTION.md
│   ├── WIRING_AND_PROTECTION.md
│   └── datasheets/README.md
├── calculations/
│   ├── POWER_CALCULATION_TEMPLATE.md
│   ├── WIND_OUTPUT_TEMPLATE.csv
│   └── SOLAR_OUTPUT_TEMPLATE.csv
├── testing/
│   ├── TEST_PROTOCOL.md
│   ├── RAW_DATA_TEMPLATE.csv
│   └── VALIDATION_STATUS.md
├── software/
│   ├── esp32/README.md
│   ├── mppt/README.md
│   └── dashboard/README.md
├── simulation/
│   └── README.md
├── media/
│   ├── README.md
│   ├── prototype_photos/
│   └── prototype_video/
├── references/
│   └── README.md
└── team/
    └── TEAM.md
```

## 7. Current Design Targets

The uploaded project document specifies:
- Solar capacity: 80 W
- Target budget: approximately ₹50,000
- Prototype budget listed in the document: ₹48,500
- Wind subsystem: up to 8 low-KV BLDC/gimbal motors
- Tree height: approximately 2.5 m
- Target applications: IoT devices, small DC loads, lighting, campuses and public spaces

These are design/document values unless supported by measured evidence.

## 8. Development Philosophy

GreenVolt is being developed as an experimentally validated hardware system. Generator output, rotor performance, conversion losses, battery behavior and overall energy yield must be established through testing rather than inferred from motor nameplate ratings.

## 9. Team

See `team/TEAM.md`.

## 10. Status

**Prototype / Engineering Validation**

The repository is intended to provide transparent technical evidence for judges, reviewers and future development.
