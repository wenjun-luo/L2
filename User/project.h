#ifndef __PROJECT__
#define __PROJECT__

#include "Radar.h"
#include "BreatheLED.h"
#include "H/Function_Init.H"
#include "..\TKDriver\H\TKDriver.h" 
#include "H/RingBuffer_C51.H"


#define SEND_HANDER1 0xAA
#define SEND_HANDER2 0x88
#define SEND_LEN     0x07

u8 handle_tft2mcu_data(uint8_t *buf);
u8 handle_mcu2tft_data(uint8_t *buf, int len);
u8 handle_tft2mcu_datacheck(uint8_t *buf, int len);
void loop_recv_comunicate_data(uint8_t *com_data);
void loop_write_comunicate_data(void);
void Radar_work(void);
void project(void);
extern uint8_t is_200ms_tick(uint8_t clear);
extern uint8_t is_100us_tick(uint8_t clear);
extern void PWMDTY1_Set(void);
extern void UART_Sendstring(u8 *str);

extern uint8_t RadarFlag;
extern uint8_t Uart1_RxData[7];
#define STEPVALUE (Uart1_RxData[5] + (0xFF - Uart1_RxData[5]) * 2 - 0xFF)

#endif 