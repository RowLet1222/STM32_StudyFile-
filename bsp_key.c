#include	"bsp_key.h"
#include	"stm32f10x.h"

void	KEY_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStruct;
	
	GPIO_InitStruct.GPIO_Mode	=	GPIO_Mode_IN_FLOATING;					//配置GPIO端口为浮空输入模式
	GPIO_InitStruct.GPIO_Speed	=	GPIO_Speed_50MHz;			
	
	GPIO_InitStruct.GPIO_Pin	=	KEY1_GPIO_PIN;									//设置KEY1的引脚
	
	RCC_APB2PeriphClockCmd(KEY1_GPIO_CLK,ENABLE);								//开启KEY1所在总线的时钟
	GPIO_Init(KEY1_GPIO_PORT,&GPIO_InitStruct);									//初始化KEY1所在的GPIO引脚
	
	GPIO_InitStruct.GPIO_Pin	=	KEY3_GPIO_PIN;									//设置KEY3的引脚
	
	RCC_APB2PeriphClockCmd(KEY3_GPIO_CLK,ENABLE);								//开启KEY1所在总线的时钟
	GPIO_Init(KEY3_GPIO_PORT,&GPIO_InitStruct);									////初始化KEY1所在的GPIO引脚
	
}

uint8_t	KEY_Scan(GPIO_TypeDef *	GPIOx	,	uint16_t	GPIO_Pin)
{
	
	if	(GPIO_ReadInputDataBit(GPIOx	,	GPIO_Pin)	==	KEY_ON)
		{
			while	(GPIO_ReadInputDataBit(GPIOx	,	GPIO_Pin)	==	KEY_ON);
			return	KEY_ON;}
	else	return	KEY_OFF;
		
}
