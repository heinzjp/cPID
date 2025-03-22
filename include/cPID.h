#ifndef C_PID_H
#define C_PID_H

typedef struct {
    float Kp;           // Proportional gain
    float Ki;           // Integral gain
    float Kd;           // Derivative gain
    float previous_error; // Last error value
    float integral;      // Integral of errors
    float setpoint;      // Desired value (target)
    float min_output;    // Minimum output limit (optional)
    float max_output;    // Maximum output limit (optional)
} cPID;

// Function prototypes
void cPID_Init(cPID *pid, float Kp, float Ki, float Kd, float setpoint, float min_output, float max_output);
float cPID_Compute(cPID *pid, float current_value);
void cPID_Reset(cPID *pid);
void cPID_Tune(cPID *pid, float Kp, float Ki, float Kd);

#endif