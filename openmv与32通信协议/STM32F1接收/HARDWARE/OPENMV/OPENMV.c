
/* Includes ------------------------------------------------------------------*/
#include "OPENMV.h"

/* Macro definitions ---------------------------------------------------------*/

/* Struct or Class definitions -----------------------------------------------*/

/* Extern global variables ---------------------------------------------------*/

/* Global variables ----------------------------------------------------------*/
int boll_x;
int boll_y;
/* Function declarations -----------------------------------------------------*/


/**
* @brief  OPENMV_date_anl
* @param  接收的一个字节
* @retval None
*/
void OPENMV_date_anl(u8 data)
{
	static u8 RxBuffer[10];
	static u8 state = 0;
/*通信格式 0xAA 0x55 data1 data2 checkout 0x54*/	
/*其中checkout=(data1+data2)低八位  比如 data1=0xe1,data2=0xf3,data1+data2=0x1d4,则checkout=0xd4*/
	if(state==0&&data==0xAA)
		state=1;
	else if(state==1&&data==0x55)
		state=2;
	else if(state==2)
	{
		RxBuffer[0]=data;//x
			state=3;
	}
	else if(state==3)
	{	
		RxBuffer[1]=data;//y
		state = 4;
	}
	else if(state==4)
	{	
		RxBuffer[2]=data;//checkout
		state = 5;
	}

	else if(state==5&&data==0x54)
	{	
		if(RxBuffer[2]==(u8)(RxBuffer[0]+RxBuffer[1]))//校验成功
		{
		boll_x=RxBuffer[0];
		boll_y=RxBuffer[1];
		}
	
		state = 0;
	}
	else
		state = 0;
}



/***************************END OF FILE************************************/

