#ifndef config_h
#define config_h

/*Includes ------------------------------------------------------------------*/
#include "stdio.h"
#include "math.h"
#include "string.h"
#include "stm32f4xx_gpio.h"           


/////////// Prototip Fonksiyon Basliklari ////////////

/*-------------- UART4 Konfig�rasyon -----------------
 *	
 *	UART4 i�in C portu kullanilmaktadir.
 *
 *	Rx pini -> PC11 ///// Tx Pini -> PC10
 *
 *	Parity  			 -> None 
 *	Stop Biti			 ->  1 
 *	Data Uzunlugu  -> 8 Bit
 *
 *	Kullanilan Inrettupts Flags
 *	
 *	USART_IT_RXNE - Rx Buffer Bos Flagi
 *	USART_IT_TC   - G�nderim islemi tamamlandi Flagi
 *
 *-----------------------------------------------------
 */

void config_UART4(uint32_t BaudRate,int16_t Priority ,int16_t SubPriority);

/*-------------- UART5 Konfig�rasyon -----------------
 *	
 *	UART5 i�in D portu kullanilmaktadir.
 *
 *	Rx pini -> PD2 ///// Tx Pini -> None
 *
 *	Parity  			 -> None 
 *	Stop Biti			 ->  1 
 *	Data Uzunlugu  -> 8 Bit
 *
 *	Kullanilan Inrettupts Flags
 *	
 *	USART_IT_RXNE - Rx Buffer Bos Flagi
 *	
 *-----------------------------------------------------
 */
 
 void config_UART5(int32_t BaudRate,int16_t Priority ,int16_t SubPriority);
 
 /*-------------- USART3 Konfig�rasyon --------------
 *	
 *	USART3 i�in B portu kullanilmaktadir.
 *
 *	Rx pini -> PB11 ///// Tx Pini -> None
 *
 *	Parity  			 -> None 
 *	Stop Biti			 ->  1 
 *	Data Uzunlugu  -> 8 Bit
 *
 *	Kullanilan Inrettupts Flags
 *	
 *	USART_IT_RXNE - Rx Buffer Bos Flagi
 *	
 *-----------------------------------------------------
 */
 
 void config_USART3(int32_t BaudRate,int16_t Priority ,int16_t SubPriority);
 
 /* -------------- TIM2 Encoder Mode Konfig�rasyon --------------
 *	
 *							TIM2 i�in A ve B portu kullanilmaktadir.
 *
 *							Her iki Pin Alternative Funtion durumunda
 *
 *							Her iki Kanal i�in Polarity Rising Modundadir
 *	
 *							Channel 1 	->	PA 15 Pini
 *
 *							Channel 2 	->	PB 3 Pini	
 *	
 * ----------------------------------------------------------------
 */
 
 void config_TIM2_EncoderMode_TwoChannel(void);
 
 /*--------------GPIOD Portu Konfig�rasyonlari--------------
 *
 *	Bu konfig�rasyon ayarlari stm32f407 discovery kitinin
 *	�st�nde bulunan Ledleri kullanmaktadir.
 *
 *	LED1 -> GPIO_Pin_12
 *
 *	LED2 -> GPIO_Pin_13
 *	
 *	LED3 -> GPIO_Pin_14
 *
 *	LED4 -> GPIO_Pin_15
 */
 
 void config_Hardware_LEDs(void);
 
/*
*						---------- TIM 4 i�in Timer PWM Hesabi ---------
*
*									APB1 42Mhz PLL 2 katina �ikarir 84Mhz
*									APB2 84Mhz PLL 2 katina �ikarir 168Mhz
*
*			timer_tick_frequency = Timer_default_frequency / (prescaller_set + 1) 
*
*	for example;
*
*			timer_tick_frequency = 84000000 / (0 + 1) = 84000000 
*
*			PWM_frequency = timer_tick_frequency / (TIM_Period + 1)
*
*	for example;
*
*			TIM_Period = 84000000 / 10000 - 1 = 8399 // 10Khz'lik bir pwm sinyali
*
*													PWM pini -> PB8
*
*										TB6612FNG  -> STDBY  -> PD1
*										TB6612FNG  -> INA1   -> PD3
*										TB6612FNG  -> INA2   -> PD5

*/
 
 void config_TIM10_with_PWM(int Prescaler, int Period, int RepetitionCounter, int Pulse);
 

#endif

