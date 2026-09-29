# Energy Sheet

`Energy_Sheet.xlsx` is the project energy-analysis workbook supplied by the GreenVolt team.

## Use

Use this workbook as the calculation/evidence workbook for:
- solar energy estimates
- wind energy estimates
- hybrid energy calculations
- battery/storage analysis
- daily/annual energy estimates
- supporting project calculations

## Evidence labeling

Before publishing final results, clearly distinguish:
- MEASURED
- CALCULATED
- SIMULATED
- TARGET / PROJECTED
- PLANNED

Do not present a calculated or projected value as a measured prototype result.

## Versioning

When the workbook is updated:
1. Keep the previous version if it was used in a submitted presentation.
2. Record the date and major changes in the commit message.
3. Update the README if assumptions or system architecture change.

## Architecture consistency

The project has recently moved toward a proposed 48 V shared DC-bus architecture, while some legacy project documents use 24 V. Verify the workbook's voltage, battery, controller and energy-flow assumptions before using it as evidence for the final 48 V design.
