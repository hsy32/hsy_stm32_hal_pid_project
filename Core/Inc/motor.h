#ifndef __MOTOR_H
#define __MOTOR_H
#include "main.h"
#include "stm32f4xx_hal.h"

/* 外部声明定时器句柄，解决 htim1/htim9/htim10/htim11 未定义报错 */
extern TIM_HandleTypeDef htim1;
extern TIM_HandleTypeDef htim9;
extern TIM_HandleTypeDef htim10;
extern TIM_HandleTypeDef htim11;

void motor_init(void);
void motor_youqian(int direct,int pwm);
void motor_zuoqian(int direct,int pwm);
void motor_youhou(int direct,int pwm);
void motor_zuohou(int direct,int pwm);

#endif
