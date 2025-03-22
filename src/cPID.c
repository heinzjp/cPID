#include "cPID.h"

void cPID_Init(cPID *pid, float Kp, float Ki, float Kd, float setpoint, float min_output, float max_output){
    pid->Kp = Kp;
    pid->Ki = Ki;
    pid->Kd = Kd;
    pid->setpoint = setpoint;
    pid->previous_error = 0.0f;
    pid->integral = 0.0f;
    pid->min_output = min_output;
    pid->max_output = max_output;
}

float cPID_Compute(cPID *pid, float current_value){
    float error = pid->setpoint - current_value;
    pid->integral += error;                         // Sum of past errors (Integral term)
    float derivative = error - pid->previous_error; // Change in error (Derivative term)

    // Compute PID output
    float output = (pid->Kp * error) + (pid->Ki * pid->integral) + (pid->Kd * derivative);

    // Constrain the output to the min/max range
    if (output > pid->max_output) {
        output = pid->max_output;
    } else if (output < pid->min_output) {
        output = pid->min_output;
    }

    // Save the current error for next iteration
    pid->previous_error = error;

    return output;
}

void cPID_Reset(cPID *pid){
    pid->previous_error = 0.0f;
    pid->integral = 0.0f;
}

void cPID_Tune(cPID *pid, float Kp, float Ki, float Kd){
    pid->Kp = Kp;
    pid->Ki = Ki;
    pid->Kd = Kd;
}