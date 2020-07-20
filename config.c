
/* Includes ------------------------------------------------------------------*/

#include "stm32f4xx.h"
#include <config.h>

void config_UART4(uint32_t BaudRate, int16_t Priority , int16_t SubPriority)
{
	
	GPIO_InitTypeDef 	GPIO_InitStructer;
	USART_InitTypeDef	UART_InitStructer;
	NVIC_InitTypeDef  NVIC_InitStructer;
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_UART4, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);
	
	GPIO_InitStructer.GPIO_Mode  = GPIO_Mode_AF;
	GPIO_InitStructer.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructer.GPIO_Pin	 = GPIO_Pin_11 | GPIO_Pin_10; // PC11 - Rx /// PC10 - TX
	GPIO_InitStructer.GPIO_PuPd  = GPIO_PuPd_NOPULL;
	GPIO_InitStructer.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_PinAFConfig(GPIOC , GPIO_PinSource11 , GPIO_AF_UART4);
  GPIO_PinAFConfig(GPIOC , GPIO_PinSource10 , GPIO_AF_UART4);
	
	GPIO_Init(GPIOC, &GPIO_InitStructer);

	UART_InitStructer.USART_BaudRate = BaudRate;
	UART_InitStructer.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	UART_InitStructer.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
	UART_InitStructer.USART_Parity = USART_Parity_No;
  UART_InitStructer.USART_StopBits = USART_StopBits_1;
  UART_InitStructer.USART_WordLength = USART_WordLength_8b;  
  USART_Init(UART4 , &UART_InitStructer);
	USART_Cmd(UART4 , ENABLE);
	
	USART_ClearITPendingBit(UART4, USART_IT_RXNE); 	
	USART_ClearITPendingBit(UART4, USART_IT_TC); 	
	
  USART_ITConfig(UART4, USART_IT_RXNE,ENABLE);
  USART_ITConfig(UART4, USART_IT_TC,ENABLE);

	NVIC_InitStructer.NVIC_IRQChannel = UART4_IRQn;
  NVIC_InitStructer.NVIC_IRQChannelPreemptionPriority = Priority;
  NVIC_InitStructer.NVIC_IRQChannelSubPriority = SubPriority;
  NVIC_InitStructer.NVIC_IRQChannelCmd = ENABLE;
   
  NVIC_Init(&NVIC_InitStructer);

}
void config_UART5(int32_t BaudRate,int16_t Priority ,int16_t SubPriority)
{
	GPIO_InitTypeDef 	GPIO_InitStructer;
	USART_InitTypeDef	UART_InitStructer;
	NVIC_InitTypeDef  NVIC_InitStructer;
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_UART5, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);
	
	GPIO_InitStructer.GPIO_Mode  = GPIO_Mode_AF;
	GPIO_InitStructer.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructer.GPIO_Pin	 = GPIO_Pin_2; // PD2 - Rx 
	GPIO_InitStructer.GPIO_PuPd  = GPIO_PuPd_NOPULL;
	GPIO_InitStructer.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_PinAFConfig(GPIOD , GPIO_PinSource2 , GPIO_AF_UART5);

	
	GPIO_Init(GPIOD, &GPIO_InitStructer);

	UART_InitStructer.USART_BaudRate = BaudRate;
	UART_InitStructer.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	UART_InitStructer.USART_Mode = USART_Mode_Rx;
	UART_InitStructer.USART_Parity = USART_Parity_No;
  UART_InitStructer.USART_StopBits = USART_StopBits_1;
  UART_InitStructer.USART_WordLength = USART_WordLength_8b;
   
  USART_Init(UART5 , &UART_InitStructer);
  USART_ITConfig(UART5, USART_IT_RXNE, ENABLE);
  USART_Cmd(UART5 , ENABLE);

	NVIC_InitStructer.NVIC_IRQChannel = UART5_IRQn;
  NVIC_InitStructer.NVIC_IRQChannelPreemptionPriority = Priority;
  NVIC_InitStructer.NVIC_IRQChannelSubPriority = SubPriority;
  NVIC_InitStructer.NVIC_IRQChannelCmd = ENABLE;
   
  NVIC_Init(&NVIC_InitStructer);
	
}

void config_USART3(int32_t BaudRate,int16_t Priority ,int16_t SubPriority)
{
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB , ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStruct;
	
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF;
	GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_11; // Rx -- PB11
	GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;		
	
	GPIO_Init(GPIOB , &GPIO_InitStruct);

	GPIO_PinAFConfig(GPIOB , GPIO_PinSource11 , GPIO_AF_USART3);	

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART3 , ENABLE);
	
	USART_InitTypeDef USART_InitStruct;
	
	USART_InitStruct.USART_BaudRate = BaudRate;
	USART_InitStruct.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USART_InitStruct.USART_Mode = USART_Mode_Rx;
	USART_InitStruct.USART_Parity = USART_Parity_No;
	USART_InitStruct.USART_StopBits = USART_StopBits_1;
	USART_InitStruct.USART_WordLength = USART_WordLength_8b;
	
	USART_Init(USART3 , &USART_InitStruct);
	
	USART_ITConfig(USART3, USART_IT_RXNE, ENABLE);
	USART_Cmd(USART3 , ENABLE);	
	
	NVIC_InitTypeDef NVIC_InitStruct;
	
	NVIC_InitStruct.NVIC_IRQChannel = USART3_IRQn;
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = Priority;
	NVIC_InitStruct.NVIC_IRQChannelSubPriority = SubPriority;
	NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
	
	NVIC_Init(&NVIC_InitStruct);	

}
void config_EXTI_NVIC_SYSCFG(void)
{
	GPIO_InitTypeDef GPIO_InitStruct;
	NVIC_InitTypeDef NVIC_InitStruct;
	EXTI_InitTypeDef EXTI_InitStruct;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG,ENABLE);
	
	SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOA, EXTI_PinSource1);

	EXTI_InitStruct.EXTI_Line = EXTI_Line1;
	EXTI_InitStruct.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTI_InitStruct.EXTI_LineCmd = ENABLE;
	EXTI_InitStruct.EXTI_Trigger = EXTI_Trigger_Rising_Falling;
	EXTI_Init(&EXTI_InitStruct);

	NVIC_InitStruct.NVIC_IRQChannel = EXTI1_IRQn;
	NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 0x01;
	NVIC_InitStruct.NVIC_IRQChannelSubPriority = 0x01;
	NVIC_Init(&NVIC_InitStruct);
	
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA,ENABLE);
	
	GPIO_InitStruct.GPIO_Mode  = GPIO_Mode_IN;
	GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStruct.GPIO_Pin   = GPIO_Pin_1;
	GPIO_InitStruct.GPIO_PuPd  = GPIO_PuPd_DOWN;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_Init(GPIOA, &GPIO_InitStruct);
	
	
}

void config_TIM2_EncoderMode_TwoChannel(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	
	RCC_AHB1PeriphClockCmd (RCC_AHB1Periph_GPIOA, ENABLE);
	RCC_AHB1PeriphClockCmd (RCC_AHB1Periph_GPIOB, ENABLE);
	
	GPIO_StructInit (&GPIO_InitStructure);
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_15;
  GPIO_Init (GPIOA, &GPIO_InitStructure);
	
	GPIO_StructInit (&GPIO_InitStructure);
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;
  GPIO_Init (GPIOB, &GPIO_InitStructure);
	
  GPIO_PinAFConfig (GPIOA, GPIO_PinSource15, GPIO_AF_TIM2);
	GPIO_PinAFConfig (GPIOB, GPIO_PinSource3, GPIO_AF_TIM2);
	
	RCC_APB1PeriphClockCmd (RCC_APB1Periph_TIM2, ENABLE);
	
	TIM_EncoderInterfaceConfig (TIM2, TIM_EncoderMode_TI12, 
                              TIM_ICPolarity_Rising, 
                              TIM_ICPolarity_Rising);
  TIM_SetAutoreload (TIM2, 0xFFFFFFFF);

	TIM_Cmd (TIM2, ENABLE);

}

void config_Hardware_LEDs(void)
{
	GPIO_InitTypeDef 	GPIO_InitStructer;
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);
	
	GPIO_InitStructer.GPIO_Mode  = GPIO_Mode_OUT;
	GPIO_InitStructer.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructer.GPIO_Pin	 = GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15; // PC11 - Rx /// PC10 - TX
	GPIO_InitStructer.GPIO_PuPd  = GPIO_PuPd_NOPULL;
	GPIO_InitStructer.GPIO_Speed = GPIO_Speed_50MHz;

	GPIO_Init(GPIOD, &GPIO_InitStructer);

}

void config_TIM10_with_PWM(int Prescaler, int Period, int RepetitionCounter, int Pulse)
{

	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
	TIM_OCInitTypeDef	TIM_OCInitStructure;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM10,ENABLE);
	

	/* TIM10 Ayarlari Yapiliyor */
	TIM_TimeBaseStructure.TIM_ClockDivision = 0;
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseStructure.TIM_Period = Period;
	TIM_TimeBaseStructure.TIM_Prescaler = Prescaler;
	TIM_TimeBaseInit(TIM10, &TIM_TimeBaseStructure);
	TIM_TimeBaseStructure.TIM_RepetitionCounter = RepetitionCounter;	
		/* PWM Ayarlari yapiliyor. */
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitStructure.TIM_Pulse = Pulse;
	TIM_OC1Init(TIM10, &TIM_OCInitStructure);
	TIM_OC1PreloadConfig(TIM10, TIM_OCPreload_Enable);
	TIM_ARRPreloadConfig(TIM10, ENABLE);

  TIM_Cmd(TIM10, ENABLE);
	
	GPIO_InitTypeDef 	GPIO_InitStructer;
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);
	
	GPIO_InitStructer.GPIO_Pin	 = GPIO_Pin_1 | GPIO_Pin_3 | GPIO_Pin_5; 
	GPIO_InitStructer.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructer.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructer.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_InitStructer.GPIO_PuPd = GPIO_PuPd_UP;

	GPIO_Init(GPIOD, &GPIO_InitStructer);
	
	GPIO_InitStructer.GPIO_Pin = GPIO_Pin_8;
	GPIO_InitStructer.GPIO_Mode = GPIO_Mode_AF;
	GPIO_InitStructer.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructer.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_InitStructer.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_Init(GPIOB, &GPIO_InitStructer);
	
	GPIO_PinAFConfig(GPIOB,GPIO_PinSource8,GPIO_AF_TIM10);
}
