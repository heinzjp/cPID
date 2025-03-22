#include <stdio.h>
#include <stdlib.h>
#include "cPID.h"

int main() {
    // Create a PID controller for pitch
    cPID pitch_pid;

    // Initialize PID controller (e.g., Kp=1.0, Ki=0.1, Kd=0.5, desired pitch setpoint=10 degrees)
    cPID_Init(&pitch_pid, 1.0f, 0.1f, 0.5f, 10.0f, -100.0f, 100.0f);

    // Simulate a quadcopter's pitch angle (this would come from the IMU in a real setup)
    float current_pitch = 0.0f;

    // Simulate controlling loop
    for (int i = 0; i < 100; i++) {
        // Simulate the current pitch changing slightly
        current_pitch += (rand() % 5) - 2;  // Random small change

        // Get the PID output (this will control the motors)
        float pid_output = cPID_Compute(&pitch_pid, current_pitch);

        current_pitch += pid_output * 0.2;

        // Print the control output (you would use it to adjust the motors in real code)
        printf("Current Pitch: %.2f, PID Output: %.2f\n", current_pitch, pid_output);

        // Simulate a small delay (100ms)
        usleep(100000);
    }

    return 0;
}
