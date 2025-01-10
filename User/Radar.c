#include "Radar.h"
#include "project.h"
extern uint32_t l_1ms_cnt;
//使能雷达
void Radar_open(void)
{
    P1CON &= 0xEF;
    P1PH |= 0x02; 	
	P11 = 1;
	//l_1ms_cnt = 0;
}
//高电平自检两秒和低电平1秒
void Radar_check(void)
{
	while(P14 == 1); //自检等待低电平出现
	l_1ms_cnt = 0;
    while(l_1ms_cnt <= 1000)
	{
		continue;
		if(l_1ms_cnt == 1000)
			break;
	}
	// if(P14 == 0)
	// 	return 1;
	// else
	// 	return 0;
    	
}
//检测有无感应，有感应为1，无感应为0
unsigned char Radar_Ischeck(void)
{

	if(P14 == 1)
		return 1;
	else
		return 0;

}
//雷达初始化
void Radar_init(void)
{
	Radar_open();
	Radar_check();
}



