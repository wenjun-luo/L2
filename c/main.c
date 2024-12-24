#include "project.h"
extern void PWM_Init(void);
extern void UART1_Init(uint Freq,unsigned long int baud);
extern bit BreatheLED;
void main(void)
{  
	// WDTCON |= 0x10;		    //清看门狗
    IO_Init();
    Timer_Test();
	PWM_Init();
	Radar_init();
    TouchKeyInit();
	UART1_Init(12,9600);
    while(1)
    {
		//功能总入口
         project();   
		//呼吸灯		
		if(BreatheLED)
			PWMDTY1_Set();
		
    }
    
}
