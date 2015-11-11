#include "includes.h"

#include "delay.h"
#include "usart.h"

#include "ff.h"
#include "exfuns.h"
#include "w25qxx.h"

#include "sram.h"
#include "ILI93xx.h"
#include "touch.h"
#include "led.h"
#include "key.h"

#include "sweeprobot_testing.h"

#include "GUIDEMO.h"

int main(void)
{
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	delay_init(168);
	uart_init(115200);
	TFTLCD_Init();
	W25QXX_Init();
	LED_Init();
	KEY_Init();
    TIM3_Int_Init(9999,168-1);
	FSMC_SRAM_Init();

	mem_init(SRAMIN);
	mem_init(SRAMEX);
	mem_init(SRAMCCM);

	exfuns_init();
	f_mount(fs[0],"0:",1);
	f_mount(fs[1],"1:",1);

	OSInit();
	OS_Task_Create();
	OSStart();

  /* XXX: should never get here */
	while(1){

	}

	return -1;
}
