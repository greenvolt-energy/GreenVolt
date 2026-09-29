# GreenVolt — GitHub Upload Guide

## Step 1 — Create the repository

1. Sign in to GitHub.
2. Click **New repository**.
3. Repository name:
   `GreenVolt-SIH-2026`
4. Description:
   `GreenVolt — Hybrid Wind-Solar Energy Tree | Smart India Hackathon 2026 | PS 26217`
5. Select **Public** if this is the judge-facing repository.
6. Do not add another README if this bundle already contains one.
7. Create the repository.

## Step 2 — Prepare the local folder

Extract:
`GreenVolt-SIH-2026-GitHub-Complete-Bundle.zip`

The extracted folder should be named:
`GreenVolt-SIH-2026`

## Step 3 — Add your actual evidence

Before publishing, add:

### Prototype
- actual prototype photos
- full prototype video
- CAD files
- wiring diagram
- circuit diagram
- AeroLeaf dimensions/drawing

### Hardware
- verified BOM
- component datasheets
- battery/BMS specification
- MPPT/controller datasheets
- generator datasheets
- protection-device ratings

### Testing
- raw measurement CSV files
- test setup photos
- multimeter/instrument photos
- solar test results
- wind test results
- hybrid test results
- battery test results

### Software
- ESP32 code
- sensor calibration code
- MPPT implementation
- dashboard code
- MATLAB/Simulink models

### Evidence
Every result should be labeled:
MEASURED / CALCULATED / SIMULATED / TARGET / PLANNED.

## Step 4 — Check secrets

Never upload:
- Wi-Fi passwords
- MQTT passwords
- API keys
- tokens
- cloud credentials
- private keys
- personal confidential files

## Step 5 — Upload through GitHub website

Open the repository.

Click:
**Add file → Upload files**

Drag the complete contents of the extracted `GreenVolt-SIH-2026` folder into the upload area.

For large files, use Git LFS or GitHub Releases rather than putting very large binaries directly into normal Git history.

Enter commit message:
`Initial GreenVolt SIH 2026 technical evidence repository`

Click:
**Commit changes**

## Step 6 — Verify the repository

Open the public repository and check:

- README renders correctly
- all folders open
- Energy_Sheet.xlsx downloads/opens
- PDFs open
- images display
- source code is visible
- no credentials are exposed
- links work

## Step 7 — Add the GitHub link to the SIH PPT

Use the public repository URL in the PPT.

Recommended link text:

**GitHub — Technical Evidence & Prototype Documentation**

## Step 8 — Final judge path

A judge should be able to follow:

README
→ System Architecture
→ Hardware / BOM
→ Prototype Photos
→ Measurements
→ Calculations
→ ESP32 / Software
→ Video
→ Future Scope

without needing permission.

## Step 9 — Final consistency check

Before submission, verify that:
- final bus voltage is consistent everywhere
- battery voltage matches the final architecture
- controller ratings match the bus
- dashboard numbers match measurements
- theoretical results are labeled
- prototype claims have evidence
