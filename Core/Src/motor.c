#include "motor.h"
void motor_init()
{		
		HAL_TIM_PWM_Start(&htim10, TIM_CHANNEL_1);
		HAL_TIM_PWM_Start (&htim11,TIM_CHANNEL_1);}


void motor_zuohou(int direct,int pwm)
{if(direct==1)
		{__HAL_TIM_SET_COMPARE(&htim10, TIM_CHANNEL_1, 0);
		 __HAL_TIM_SET_COMPARE(&htim11, TIM_CHANNEL_1, pwm);
		}
else if(direct==0)
{
__HAL_TIM_SET_COMPARE(&htim11, TIM_CHANNEL_1, 0);
__HAL_TIM_SET_COMPARE(&htim10, TIM_CHANNEL_1, pwm);	
}
}
