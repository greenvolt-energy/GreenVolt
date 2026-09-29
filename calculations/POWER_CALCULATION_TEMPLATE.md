# Power Calculation Template

## Electrical power

P = V × I

Example format:

| Source | Voltage (V) | Current (A) | Power (W) | Status |
|---|---:|---:|---:|---|
| Solar | enter measured | enter measured | V × I | MEASURED |
| Wind | enter measured | enter measured | V × I | MEASURED |
| Bus | enter measured | enter measured | V × I | MEASURED |

## Wind theoretical estimate

P_wind = 0.5 × rho × A × v^3 × C_p × eta

Where:
- rho = air density
- A = swept area
- v = wind speed
- Cp = power coefficient
- eta = electrical/mechanical efficiency factor

Clearly label theoretical values as CALCULATED.

## Solar estimate

P_solar = G × A × eta_panel × bifacial_factor × eta_system

Use actual panel datasheet values and measured irradiance where available.

## Hybrid output

Do not simply add rated/nameplate values.

Use measured subsystem output after conversion losses:

P_hybrid = P_solar_measured + P_wind_measured

For energy:

E = integral(P dt)

or sum sampled power over time.

## Battery energy

For a battery:

E_nominal ≈ V_nominal × Ah

Actual usable energy depends on:
- battery chemistry
- depth of discharge
- efficiency
- temperature
- discharge rate
