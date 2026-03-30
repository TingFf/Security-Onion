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

- Design Sigma detection rules  
- Convert detections into SIEM queries (KQL/EQL)  
- Configure Auditd rules for telemetry generation  
- Perform threat hunting and correlation  
- Map detections to the MITRE ATT&CK framework  

### How to emulate attack

1. Set up the Security Onion
2. On Ubuntu, configure and set up the misconfigure JupyterLab

```
1️⃣ Install the venv module
--------------------------
apt install python3-venv

2️⃣ Create a virtual environment
-------------------------------
python3 -m venv jupyter_env

3️⃣ Activate it
--------------
source jupyter_env/bin/activate
Your prompt will change to:
(jupyter_env) root@VM:~

4️⃣ Install JupyterLab
---------------------
pip install jupyterlab

5️⃣ Run JupyterLab
-----------------
jupyter lab --ip=0.0.0.0 --port=8888 --no-browser --allow-root
```

3. Access remotely on kali, transfer `polygot_downloader.sh`.
4. Set up a python server to serve the polygot images.
5. Prepare the images:
  1. Compile the rootkit to `.so` file.
  ```
  gcc -c -fPIC hideproc.c -o hideproc.o
  gcc hideproc.o -shared -o hideproc.so
  ```
  2. Embed the script into the images.
  ```
  cat panda.jpeg mal_shell > panda_v14
  cat panda.jpeg hideproc.so > panda_h14
  ```
6. Execute the `polygot_downloader.sh`.

