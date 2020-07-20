/* Includes ------------------------------------------------------------------*/

#include "stm32f4xx.h"                  // Device header
#include <stdbool.h>
#include <config.h>
#include <OzelFonksiyonlar.h>
#define toint(c)  ((c & 0x5F) > '9' ? c - '7' : c - '0')
/*	Degiskenler	-------------------------------------  */
unsigned char sayiyiParcala_Dizi[7] = {'0','0','0','0','0','0','0'};
int convertToByte[20] = {0}, pusula_Integer = 0;;
extern unsigned char veriPaketi[35];
extern unsigned char enlem_Data[10];
extern unsigned char boylam_Data[11];

uint32_t i = 0;
uint32_t k = 0;
uint32_t pusula_Sayici = 0;
uint32_t gps_Sayici = 0;
int32_t motor1Sayac = 0;
int32_t sayici = 0;
uint32_t arayuz_Sayac = 0;
uint32_t gelen_Pusula;
uint32_t gelen_Encoder;
unsigned char pusula[3] = {'0','0','0'};
unsigned char gpsAnlikByte[1] = {0};
unsigned char gpsGelen1[74] = {0};
unsigned char arayuz_Gelen_Byte[1];
char arayuz_Gelen[20];
unsigned char gps_Kontrol[6]={'$','G','P','G','G','A'};
uint8_t gelen[1];
volatile bool kontrol = false;
volatile bool arayuz_kontrol = true;
volatile int32_t sysTick = 0;


void SysTick_Handler()
{	
	sysTick++;
	motor1Sayac = TIM_GetCounter (TIM2);
	sayiyi_Parcala(motor1Sayac);
	veriPaketi_Olustur(pusula,enlem_Data,boylam_Data,sayiyiParcala_Dizi);
	
	if(kontrol == true || arayuz_kontrol == false)
		{
		GPIO_ToggleBits(GPIOD,GPIO_Pin_14);
		USART_SendData(UART4,veriPaketi[k++]);
		if(k>34){
			kontrol = false; k =0;}
		}	
		
	if(sysTick % 100 == 0)
	{
		pusula_Integer = parcala_Pusula(pusula);
		if(pusula_Integer + 5 > gelen_Pusula && pusula_Integer - 5 < gelen_Pusula)
		{
			tb_ileri();
		}
		else
			tb_dur();	
	}
	
	if(sysTick % 500 == 0)
	{
		get_Lat_Lon(gpsGelen1);
		veriPaketi_Olustur(pusula,enlem_Data,boylam_Data,sayiyiParcala_Dizi);
	}
		
	if(sysTick == 1000)//50 hz
	{		
		sysTick=0;
	}
}

void UART5_IRQHandler(void)
{
	if(USART_GetITStatus(UART5, USART_IT_RXNE) == SET)		              
	{
		GPIO_ToggleBits(GPIOD,GPIO_Pin_13);
	  gelen[0] = USART_ReceiveData(UART5);
		pusula[pusula_Sayici++] = (int)gelen[0];
	
		if(pusula_Sayici >= 3) 		
										{		pusula_Sayici = 0;		}
	
		USART_ClearITPendingBit(UART5, USART_IT_RXNE); 			
	}
}

void UART4_IRQHandler(void)
{		
	
 if(USART_GetITStatus(UART4, USART_IT_RXNE) == SET)		              
	{
		TIM2 -> CNT = 0;
		kontrol = true;		
		arayuz_Gelen_Byte[0] = USART_ReceiveData(UART4);				
		if(arayuz_Gelen_Byte[0] == 'B')									{									arayuz_kontrol = true;									}
		if(arayuz_kontrol == true)											{		arayuz_Gelen[arayuz_Sayac++] = arayuz_Gelen_Byte[0];	}
		
		if(arayuz_Gelen_Byte[0] == 'S')
		{		
			arayuz_Sayac = 0; 
			arayuz_kontrol = false;		
			parcala_Gelen_Arayuz(arayuz_Gelen); 
			for(int i=0; i<20; i++)												{										arayuz_Gelen[i] = '0';								}
						
		}
		GPIO_ToggleBits(GPIOD,GPIO_Pin_15);	
		USART_ClearITPendingBit(UART4, USART_IT_RXNE); 			
	}	
	if(USART_GetITStatus(UART4,USART_IT_TC) != RESET)
	{
		if(sysTick != 0)
		{
			kontrol = true;
		}
		
		USART_ClearITPendingBit(UART4, USART_IT_TC);
	}	
}

void USART3_IRQHandler(void)
{		
	 if(USART_GetITStatus(USART3, USART_IT_RXNE) != RESET)
    {			
			gpsAnlikByte[0] = USART_ReceiveData(USART3);			
			if(gpsAnlikByte[0] == gps_Kontrol[gps_Sayici] && gps_Sayici < 6)	{	gpsGelen1[gps_Sayici++] = gpsAnlikByte[0];	}
			else if(gps_Sayici > 5)																						{	gpsGelen1[gps_Sayici++] = gpsAnlikByte[0];
				
			if(gpsAnlikByte[0] == '\r' || gpsAnlikByte[0] == '\n' )						{								gps_Sayici = 0;								}	}
				
			USART_ClearITPendingBit(USART3, USART_IT_RXNE);												
		}	 
}

int main(void)
{
	config_Hardware_LEDs();
	config_UART4(115200, 01,01);
	config_UART5(115200, 01,02);
	config_USART3(9600,  01,03);
	config_TIM10_with_PWM(20,249,0,249);
	config_TIM2_EncoderMode_TwoChannel();
	
	GPIO_InitTypeDef ufuk;
	ufuk.GPIO_Mode = GPIO_Mode_IN;
	ufuk.GPIO_OType = GPIO_OType_PP;
	ufuk.GPIO_Pin = GPIO_Pin_0;
	ufuk.GPIO_PuPd = GPIO_PuPd_DOWN;
	ufuk.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_Init(GPIOA,&ufuk);	
	//TIM2 -> CR1 = 0;   Encoder okuma enable/disable
	SystemCoreClockUpdate();
	SysTick_Config(SystemCoreClock / 1000);
	
	while(1)
	{
		
		if(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_0))
		{
			GPIO_ToggleBits(GPIOD,GPIO_Pin_12);			
		}	
	}	
}

