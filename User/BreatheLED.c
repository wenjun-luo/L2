#include "BreatheLED.h"
#include "project.h"
//ms级别，若到达则清空重新累计
extern uint8_t is_ms_tick(uint8_t clear);
uint8_t pwm1_duty = 0x64;  //LED 的pwm满状态
bit flag = 0;
// 设置PWM占空比    Uart1_RxData[5]值越大，呼吸频率越慢
void PWMDTY1_Set(void) 
{
    if (is_ms_tick(1)) 
	{  // 检查是否到达1ms
        if (flag == 0) 
		{
            PWMDTY1 = pwm1_duty;  // 设置PWM占空比
            pwm1_duty -= 1;  // 减少占空比
            if (pwm1_duty == 0) 
			{
                flag = 1;  // 改变方向
            }
        }
		else 
		{
            PWMDTY1 = pwm1_duty;  // 设置PWM占空比
            pwm1_duty += 1;  // 增加占空比
            if (pwm1_duty == 0x64) 
			{
                flag = 0;  // 改变方向
            }
        }
    }
}
/*
// 设置PWM占空比    Uart1_RxData[5]值越大，呼吸频率越快
void PWMDTY1_Set2(void) 
{
    if (is_1ms_tick(1)) 
	{  // 检查是否到达1ms
        if (flag == 0) 
		{
            PWMDTY1 = pwm1_duty;  // 设置PWM占空比
            pwm1_duty -= 1;  // 减少占空比
            if (pwm1_duty == 0) 
			{
                flag = 1;  // 改变方向
            }
        }
		else 
		{
            PWMDTY1 = pwm1_duty;  // 设置PWM占空比
            pwm1_duty += 1;  // 增加占空比
            if (pwm1_duty == 0x64) 
			{
                flag = 0;  // 改变方向
            }
        }
    }
}
*/