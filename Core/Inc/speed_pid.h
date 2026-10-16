#ifndef __SPEED_PID_H
#define __SPEED_PID_H

#include "main.h"

typedef struct{
    double COUNTER0;
    double COUNTER1;
    float actual_speed;
    float target_speed;
    float error_speed;
    float error0_speed;
    float error_leiji;
    float KP;
    float KI;
    float KD;
    int out_pwm;
    int direct;
}PID;

void capture_speed(PID *X,TIM_HandleTypeDef *htim);
void pid_calculate(PID *X);
void capture_speed2(PID *X,TIM_HandleTypeDef *htim);
#endif


