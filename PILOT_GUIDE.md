# 🛠️ Independent Pilot Integration Manual

This guide enables third-party engineers to integrate the **CZ Bare-Metal Engine** into their active production codebase (Robotics, IoT Telemetry, Control Loops) to measure zero-crash memory stability and sub-microsecond latency.

---

## 3-Step Production Integration

### Step 1: Copy `BMS_Engine.h` to your project
Include the lightweight, single-header library:
```cpp
#include "BMS_Engine.h"

Step 2: Instantiate Engine Object
​Declare the core engine on the static stack (Zero Heap Allocation):
BMS_CrossZero_Engine cz_core(0, 5); // Start state = 0, Resolution steps = 5

Step 3: Call inside high-frequency execution loop
​Replace unconstrained floating-point calculations with bounded BMS state transitions:

void loop() {
    cz_core.process_cz_cycle(); // Executes in 0.31 µs (O(1) Constant Time)
    int current_bounded_state = cz_core.getCurrentState();
}
