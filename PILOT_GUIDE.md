# 🚀 BMS Server Core - Pilot Setup Guide

Welcome to the Pilot SDK for the BMS (Behavior Management System) Engine. This guide will help you run the zero-heap telemetry stream on your ESP32 in under 5 minutes. 

Our core focus is strictly **0 Bytes dynamic memory allocation** during runtime to ensure 100% stable execution for high-frequency systems.

---

## 🛠️ Prerequisites
* **Hardware:** ESP32 Development Board (Any standard variant).
* **Software:** Arduino IDE or VS Code with PlatformIO.

---

## ⚙️ Step 1: Installation & Setup
1. **Clone the Repository:**
   Open your terminal and run:
   ```bash
   git clone [https://github.com//BMS-Server-Core.git](https://github.com/CZ-Engine-Prashun/BMS-Server-Core.git)
🚀 Step 2: Flashing to Hardware
Connect your ESP32 board to your PC via USB.

In Arduino IDE, go to Tools > Board and select your ESP32 module (e.g., "DOIT ESP32 DEVKIT V1").

Go to Tools > Port and select the active COM port.

Click the Upload button.

📊 Step 3: Verifying the Benchmarks
Once the upload is complete, open the Serial Monitor.

Set the baud rate to 115200.

You should immediately see the real-time telemetry engine start up. The output will look like this:

Plaintext
[BMS PILOT] ENGINE STARTED.
[BMS] Packet #10 | State: 1 | Latency: 0ms | Free Heap: 295000 B
[BMS] Packet #11 | State: 1 | Latency: 0ms | Free Heap: 295000 B
[BMS] Packet #12 | State: 1 | Latency: 0ms | Free Heap: 295000 B
🎯 The Stress Test Challenge
The architectural rule of this engine is absolute memory stability.

Your Task:
Let this stream run for 1 hour, 12 hours, or 24 hours. Monitor the Free Heap value. Because of the strict O(1) mathematical routing and zero-heap allocation, the heap memory will not drop by a single byte, and latency will remain constant.

🐛 Found a memory leak or crash? Please open a GitHub Issue!

⚡ Successfully verified the benchmark? Share your run-time stats with us in the community!
