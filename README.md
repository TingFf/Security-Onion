# Security-Onion
This is a small onboarding project that I did during my first 3 month at HTX as a threat hunter.

## Objective

- End-to-End Threat Research and Detection on Windows & Linux using Security Onion
- Researching an active specific (Linux) threat campaign.
- Developing detection logic (Sigma rules, queries).
- Deploying and managing Fleet Agents in Security Onion for endpoint telemetry.
- Simulating adversarial TTPs to generate logs and validate detections.

## Koske Malware Detection Engineering (Sigma + Auditd + EQL)

### Overview

This repository presents an end-to-end detection engineering project based on the Koske malware campaign, focusing on Linux-based attack techniques and telemetry from Auditd, Zeek, and process monitoring.

The project demonstrates how to:

Design Sigma detection rules
Convert detections into SIEM queries (KQL/EQL)
Configure Auditd rules for telemetry generation
Perform threat hunting and correlation
Map detections to the MITRE ATT&CK framework
