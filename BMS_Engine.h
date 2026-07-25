// BMS_Engine.h - Core Production Engine Header
#ifndef BMS_ENGINE_H
#define BMS_ENGINE_H

#include <Arduino.h>

class BMS_CrossZero_Engine {
private:
    int current_state;      // Current Discrete State (Range: 0-9)
    int target_state;       // Target Discrete State (Range: 0-9)
    float cz_phase;         // Cross-Zero Phase Bridge [0.0f to 1.0f]
    int resolution_steps;   // Step count across finite continuum

public:
    // Zero dynamic memory constructor (Strict Stack Allocation)
    BMS_CrossZero_Engine(int start_val = 0, int steps = 5) {
        current_state = start_val % 10;
        target_state = (start_val + 1) % 10;
        cz_phase = 0.0f;
        resolution_steps = (steps > 0) ? steps : 5;
    }

    // O(1) Constant-Time State Transition Loop
    inline void process_cz_cycle() {
        if (cz_phase >= 1.0f) {
            // State Collapse & Cross-Zero Transmutation
            current_state = target_state;
            target_state = (current_state + 1) % 10;
            cz_phase = 0.0f;
            return;
        }
        cz_phase += (1.0f / (float)resolution_steps);
    }

    // Get Current State & Phase Progress
    inline int getCurrentState() const { return current_state; }
    inline int getTargetState() const { return target_state; }
    inline float getPhaseProgress() const { return cz_phase * 100.0f; }
};

#endif // BMS_ENGINE_H
