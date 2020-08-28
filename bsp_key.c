#include	"bsp_key.h"
#include	"stm32f10x.h"

void	KEY_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStruct;
	
	GPIO_InitStruct.GPIO_Mode	=	GPIO_Mode_IN_FLOATING;					//����GPIO�˿�Ϊ��������ģʽ
	GPIO_InitStruct.GPIO_Speed	=	GPIO_Speed_50MHz;			
	
	GPIO_InitStruct.GPIO_Pin	=	KEY1_GPIO_PIN;									//����KEY1������
	
	RCC_APB2PeriphClockCmd(KEY1_GPIO_CLK,ENABLE);								//����KEY1�������ߵ�ʱ��
	GPIO_Init(KEY1_GPIO_PORT,&GPIO_InitStruct);									//��ʼ��KEY1���ڵ�GPIO����
	
	GPIO_InitStruct.GPIO_Pin	=	KEY3_GPIO_PIN;									//����KEY3������
	
	RCC_APB2PeriphClockCmd(KEY3_GPIO_CLK,ENABLE);								//����KEY1�������ߵ�ʱ��
	GPIO_Init(KEY3_GPIO_PORT,&GPIO_InitStruct);									////��ʼ��KEY1���ڵ�GPIO����
	
}

uint8_t	KEY_Scan(GPIO_TypeDef *	GPIOx	,	uint16_t	GPIO_Pin)
{
	
	if	(GPIO_ReadInputDataBit(GPIOx	,	GPIO_Pin)	==	KEY_ON)
		{
			while	(GPIO_ReadInputDataBit(GPIOx	,	GPIO_Pin)	==	KEY_ON);
			return	KEY_ON;}
	else	return	KEY_OFF;
		
}
