#include "speed_pid.h"

void capture_speed(PID *X,TIM_HandleTypeDef *htim)
{
    __DSB();
    X->COUNTER0 = X->COUNTER1;
    X->COUNTER1 = __HAL_TIM_GET_COUNTER(htim);
    X->actual_speed = (int16_t)(X->COUNTER1 - X->COUNTER0);
}
void capture_speed2(PID *X,TIM_HandleTypeDef *htim)
{
    __DSB();
    X->COUNTER0 = X->COUNTER1;
    X->COUNTER1 = -__HAL_TIM_GET_COUNTER(htim);
    X->actual_speed = (int16_t)(X->COUNTER1 - X->COUNTER0);
}
void pid_calculate(PID *X)
{		
    X->error0_speed = X->error_speed;
    X->error_speed = X->target_speed - X->actual_speed;
    X->error_leiji += X->error_speed;
    if(X->error_leiji>=2500)
			X->error_leiji=2500;
		    if(X->error_leiji<=-2500)
			X->error_leiji=-2500;
    X->out_pwm = (X->KP * X->error_speed) + (X->KI * X->error_leiji) + (X->KD * (X->error0_speed - X->error_speed));

				
    if(X->out_pwm >= 2000)
    {
        X->out_pwm = 2000;
    }
    if(X->out_pwm <= -2000)
    {
        X->out_pwm = -2000;
    }
    if(X->out_pwm < 0)
    {
        X->out_pwm = -X->out_pwm;
        X->direct = 0;
    }
    else
    {
        X->direct = 1;
    }
}

// ←这里回车留空行
