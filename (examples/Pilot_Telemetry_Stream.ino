#include <Arduino.h>
#include "BMS_Engine.h"

// Instantiate CZ Engine Core
BMS_CrossZero_Engine cz_sensor_engine(0, 5);

unsigned long processed_count = 0;
unsigned long start_timestamp = 0;

void setup() {
    Serial.begin(115200);
    delay(1000);
    
    Serial.println("\n==================================================");
    Serial.println("   PILOT DEPLOYMENT: REAL-TIME TELEMETRY ENGINE   ");
    Serial.println("==================================================");
    Serial.println("[STATUS] Integrating BMS V4.2 Core with High-Frequency Data Stream...");
    
    start_timestamp = millis();
}

void loop() {
    // 1. Simulate High-Frequency Telemetry Input Stream (e.g. IMU/Gyro/Sensor)
    cz_sensor_engine.process_cz_cycle();
    processed_count++;

    // 2. Telemetry Status Log Every 50,000 Data Packets
    if (processed_count % 50000 == 0) {
        uint32_t current_heap = ESP.getFreeHeap();
        unsigned long elapsed_ms = millis() - start_timestamp;
        
        Serial.printf("[PILOT STREAM] Packets: %lu | Active State: %d | Phase: %.0f%% | Heap Memory: %u Bytes\n",
                      processed_count, 
                      cz_sensor_engine.getCurrentState(), 
                      cz_sensor_engine.getPhaseProgress(),
                      current_heap);
    }
}
