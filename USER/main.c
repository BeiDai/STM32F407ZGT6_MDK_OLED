#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "led.h"
#include "oled.h"


int main(void)
{ 
	u8 t=0;
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//设置系统中断优先级分组2
	delay_init(168);     //初始化延时函数
	uart_init(115200);	//初始化串口波特率为115200
	LED_Init();					//初始化LED
 	OLED_Init();				//初始化OLED

  OLED_ShowString(0,0," STM32F407ZGTGT6 2.4'",12);  
//	OLED_ShowString(0,24, "2.4' OLED TEST",16);  
// 	OLED_ShowString(0,40,"ATOM 2017/12/5",12);  
// 	OLED_ShowString(0,52,"ASCII:",12);  
// 	OLED_ShowString(64,52,"CODE:",12); 
//		OLED_DrawPoint(0,0,1);
//		OLED_DrawPoint(127,0,1);
//		OLED_DrawPoint(0,63,1);
//		OLED_DrawPoint(127,63,1);
//		OLED_DrawPoint(63,31,1);
//		OLED_Fill(10,25,14,29,1);
//	  OLED_Fill(10,15,14,19,1);
//		OLED_Fill(10,35,14,39,1);
//		OLED_Fill(10,45,14,49,1);
//		OLED_Fill(0,0,127,63,1);
	OLED_Refresh_Gram();//更新显示到OLED	 
	t=' ';  
	while(1) 
	{		
		OLED_ShowChar(36,28,t,12,0);//显示ASCII字符	
		OLED_ShowNum(82,28,t,3,12);	//显示ASCII字符的码值    
		OLED_Refresh_Gram();        //更新显示到OLED
		t++;
		if(t>'~')t=' ';  
		delay_ms(5000);
		LED0=!LED0;

	}

	
}
