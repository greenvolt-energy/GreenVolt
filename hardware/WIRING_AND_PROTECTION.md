# Wiring and Protection

## Source branches

Each solar and wind branch should be individually identifiable and isolatable.

## Recommended documentation

Create a wiring diagram showing:
- source positive/negative
- rectifier
- MPPT/controller
- fuse
- isolator
- blocking diode if required
- common bus
- battery
- load
- ESP32 sensing points
- emergency stop

## 48 V architecture requirement

If the final architecture is 48 V, all components must be selected and documented for 48 V operation.

Do not reuse the legacy 24 V battery/controller/inverter specifications without verification.

## Cable sizing

Select cables based on:
- maximum current
- cable length
- allowable voltage drop
- temperature
- insulation rating
- installation environment

## Safety

Use suitable:
- DC-rated fuses/breakers
- isolators
- enclosure
- grounding/earthing
- emergency stop
- mechanical guarding
