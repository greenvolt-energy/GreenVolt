# Architecture Status

## Critical consistency note

The uploaded project documentation contains a **24 V DC architecture** in several sections, including the energy-generation, battery, BOM and development-plan sections.

The latest project direction requested by the team is a **48 V shared DC bus**.

These two versions must not be mixed in the final evidence.

## Latest proposed architecture

```text
SOLAR PV
   ↓
PV PROTECTION
   ↓
SOLAR MPPT / DC-DC
   ↓
                ┌───────────────┐
WIND VAWT      →│               │
   ↓            │  SHARED 48 V  │
GENERATOR       │    DC BUS     │
   ↓            │               │
3-PHASE         └──────┬────────┘
RECTIFIER              │
   ↓                   ├── LiFePO4 Battery + BMS
WIND MPPT /             ├── Supercapacitor Buffer
POWER CONDITIONING      └── DC Load / Inverter
```

## Required verification before claiming 48 V as implemented

Verify that the physical prototype actually uses:
- 48 V battery/storage architecture
- 48 V-compatible solar charge controller / MPPT
- wind-side controller compatible with the bus
- DC-DC converters rated for the required input/output
- BMS rated for the selected battery configuration
- fuses/breakers/isolators with suitable voltage/current ratings
- connectors and cable insulation suitable for the bus
- DC load and inverter compatibility
- emergency-stop and braking circuitry compatibility

## Evidence rule

Until those items are physically verified, describe the 48 V architecture as:

> "Latest proposed 48 V system architecture"

Do not label it as "measured" or "implemented" solely because it appears in a diagram.

## Legacy 24 V references

The source project document includes 24 V references in:
- common DC bus
- battery
- charge controller
- inverter
- development plan
- expected output section
- reviewer responses

These should be updated or explicitly marked obsolete before final public submission.
