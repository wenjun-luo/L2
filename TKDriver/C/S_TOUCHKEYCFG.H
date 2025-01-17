//*************************************************************************************************
//Copyright (c) ????????????
//????:  S_TouchKeyCFG.h
//??: 
//????:  ???????
//??:  V0.2
//????:
//************************************************************************************************
#ifndef __S_TOUCHKEYCFG_H__
#define __S_TOUCHKEYCFG_H__
#define		    SOCAPI_SET_TOUCHKEY_TOTAL					  1
#define			SOCAPI_SET_TOUCHKEY_CHANNEL					  0x00000001
#define			SOCAPI_SET_TOUCHKEY_CHANNEL2			      0x00000000
unsigned int  code TKCFG[17] = {0,0,0,15,10,3000,200,100,5,0,0,4,0,1,65535,65535,20}; 
unsigned char code TKChannelCfg[1][8]={
0x02,0x32,0x04,0x08,0x3a,0x05,0x02,0xa2,
};
#endif
