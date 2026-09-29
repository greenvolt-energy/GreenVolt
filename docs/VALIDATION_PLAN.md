# Validation Plan

## Test 1 — Solar-only

Measure:
- PV voltage
- PV current
- PV power
- irradiance
- panel temperature if available
- time

Test under:
- clear sky
- partial cloud
- low irradiance

## Test 2 — Wind-only

Measure:
- wind speed
- rotor RPM
- generator voltage
- generator current
- electrical power
- mechanical behavior

Test at multiple wind speeds.

## Test 3 — Individual generator characterization

For each generator:
- RPM vs voltage
- RPM vs current under load
- load vs output
- starting behavior
- rectifier losses

## Test 4 — Hybrid operation

Run solar and wind together.

Record:
- source contribution
- bus voltage
- battery current
- load current
- total power

## Test 5 — Protection

Verify:
- overcurrent protection
- isolation
- emergency stop
- braking response
- safe shutdown

## Test 6 — Monitoring validation

Compare ESP32 readings against a trusted external instrument.

Record:
- sensor reading
- reference reading
- error
- timestamp

## Evidence package

For every experiment store:
- raw CSV
- test setup photograph
- instrument photograph
- wiring photograph
- calculation sheet
- result graph
- test date
- operator
- conditions
