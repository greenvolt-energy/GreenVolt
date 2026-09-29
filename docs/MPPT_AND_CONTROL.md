# MPPT and Control Strategy

## Solar MPPT

Candidate methods:
- Perturb and Observe (P&O)
- Incremental Conductance

Inputs:
- PV voltage
- PV current
- irradiance where available
- panel temperature where available

Output:
- DC-DC converter control / operating-point adjustment

## Wind MPPT

The project proposes fuzzy-logic MPPT for the wind subsystem.

Possible inputs:
- wind speed
- generator voltage
- generator current
- rotor RPM
- power variation

The controller should be validated experimentally before claiming improved energy extraction.

## General power measurement

Electrical power:

P = V × I

Where:
- P = electrical power in watts
- V = voltage in volts
- I = current in amperes

For each subsystem, record:
- timestamp
- voltage
- current
- power
- RPM where applicable
- wind speed where applicable
- irradiance where applicable
- operating mode

## Evidence rule

Do not label simulated, calculated or assumed values as measured.
