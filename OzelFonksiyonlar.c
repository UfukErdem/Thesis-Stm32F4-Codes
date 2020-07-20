
/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx.h"                  
#include <OzelFonksiyonlar.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>

extern unsigned char sayiyiParcala_Dizi[7];
extern unsigned char gpsGelen1[80];
extern char arayuz_Gelen[20];
extern int convertToByte[20];
extern uint32_t gelen_Pusula;
extern uint32_t gelen_Encoder;
extern unsigned char pusula[3];
unsigned char enlem_Data[10] 				= {0};
unsigned char boylam_Data[11] 			= {0};
unsigned char veriPaketi[35];


void sayiyi_Parcala(uint32_t sayi)
{
	for(int j=0; j<7; j++)																					{			sayiyiParcala_Dizi[j] = ('0');			}
		
	int result;
	int i = 0;
  int taban;
    
   	if(sayi <10)							{		result = 1;	   }    
   	if(sayi >= 10)						{		result = 2;    }
   	if(sayi >= 100)						{   result = 3;	   }   
   	if(sayi >= 1000)					{		result = 4;    }         
   	if(sayi >= 10000)					{		result = 5;	   } 
   	if(sayi >= 100000)				{		result = 6;	   }      
   	if(sayi >= 1000000)				{		result = 7;	   } 
		
    switch(result)
   {  
		case 1:  
			sayiyiParcala_Dizi[6] = sayi + 48;            
		break;        
		
    case 2:  
			taban = sayi/10;
			sayiyiParcala_Dizi[5] = taban + 48;
			sayi = sayi - taban * 10;
			sayiyiParcala_Dizi[6] = sayi + 48;       
		break;       
         
    case 3:
			for(i=6; i>=4; i--)	{
					 
				if(sayi < 10)																							{		sayiyiParcala_Dizi[i] = sayi + 48;		}
					taban = sayi%(10);
					sayiyiParcala_Dizi[i] = taban + 48;
					sayi = sayi/10;                     
         }   		 
    break;
         
    case 4:
			for(i=6; i>=3; i--)	{
					 
				if(sayi < 10)																							{		sayiyiParcala_Dizi[i] = sayi + 48;		}
					taban = sayi%(10);
          sayiyiParcala_Dizi[i] = taban + 48;
          sayi = sayi/10;                     
        }     			 
    break;
         
    case 5:
			for(i=6; i>=2; i--)	{
					 
				if(sayi < 10)																							{		sayiyiParcala_Dizi[i] = sayi + 48;		}            
					taban = sayi%(10);
          sayiyiParcala_Dizi[i] = taban + 48;
          sayi = sayi/10;                     
        }     			 
    break;
         
    case 6:
			for(i=6; i>=1; i--)	{
					 
				if(sayi < 10)																							{		sayiyiParcala_Dizi[i] = sayi + 48;		}           
					taban = sayi%(10);
          sayiyiParcala_Dizi[i] = taban + 48;
          sayi = sayi/10;                     
        } 		 
    break;

    case 7:
		  for(i=6; i>=0; i--)	{
				
				if(sayi < 10)																							{		sayiyiParcala_Dizi[i] = sayi + 48;		}              
					taban = sayi%(10);
          sayiyiParcala_Dizi[i] = taban + 48;
          sayi = sayi/10;                     
        }  		 
		break;		
	}
}

int Convert_ToByte(uint32_t sayi)
{
	int basamak = 0;
	int8_t mod;
	
	for(basamak=0; sayi>8; basamak++)
	{
		mod = sayi%8;
		convertToByte[basamak] = mod;
		sayi = sayi / 8;	
	}
	if(sayi < 8)
		convertToByte[basamak] = sayi;
	
	return basamak + 1;
}
void get_Lat_Lon(unsigned char gpsGelen[])
{
	volatile bool paket_Kontrol 	= false;
	int gpsData_Sayici 						= 0;
	int ilk_Virgul_Sayici 				= 0;
	int ikinci_Virgul_Sayici 			= 0;
	int ucuncu_Virgul_Sayici 			= 0;
	int dorduncu_Virgul_Sayici 		= 0;
	int case_Virgul_Sayici 				= 0;
	int 				i 								= 0;
	
	while(1)	{
	if(gpsData_Sayici >= 79)											{		break;		}
	if(gpsGelen[gpsData_Sayici] == '$')						{	gpsData_Sayici++;	
	
		if(gpsGelen[gpsData_Sayici] == 'G')						{	gpsData_Sayici++;
			
			if(gpsGelen[gpsData_Sayici] == 'P')						{	gpsData_Sayici++;
				
				if(gpsGelen[gpsData_Sayici] == 'G')						{	gpsData_Sayici++;
			
					if(gpsGelen[gpsData_Sayici] == 'G')						{	gpsData_Sayici++;
					
						if(gpsGelen[gpsData_Sayici] == 'A')						{	paket_Kontrol = true;	 gpsData_Sayici += 2; 	break;}	
	
							} } } } }
							else 																						{		gpsData_Sayici++; 	}}
					
	if(paket_Kontrol == true) {
		
		while(1)
		{
			if(case_Virgul_Sayici >= 80)							{								break;							}
			switch(gpsGelen[gpsData_Sayici++])
			{
				case ',':
				case_Virgul_Sayici++;
				if(case_Virgul_Sayici == 1)	{	ilk_Virgul_Sayici = gpsData_Sayici;						}
				if(case_Virgul_Sayici == 2)	{	ikinci_Virgul_Sayici = gpsData_Sayici - 1;		}
				if(case_Virgul_Sayici == 3)	{	ucuncu_Virgul_Sayici = gpsData_Sayici;				}
				if(case_Virgul_Sayici == 4)	{	dorduncu_Virgul_Sayici = gpsData_Sayici - 1;	}				
				break;				
			}
			
		if(case_Virgul_Sayici == 4)	{		break;	}	
		}
		i=0;
		while(ilk_Virgul_Sayici < ikinci_Virgul_Sayici)				{		enlem_Data[i++] = gpsGelen[ilk_Virgul_Sayici++];			}	
		i=0;
		while(ucuncu_Virgul_Sayici < dorduncu_Virgul_Sayici)	{		boylam_Data[i++] = gpsGelen[ucuncu_Virgul_Sayici++];	}
	}
}

double convertUcharArrayToFloat(unsigned char dizi[],int noktaIndex,int son_Nokta)
{
	double deger = 0;
	
	for(int i=0,j=noktaIndex - 2; i< noktaIndex-1; i++,j--)
																								{		deger += (dizi[i] - 48) * pow(10,j);		}
																								
	for(int i=noktaIndex,j=1.0; i<son_Nokta; i++,j++)
																								{		deger += (dizi[i] - 48) / pow(10,j);		}
	return	deger;
}

void veriPaketi_Olustur(unsigned char P[3], unsigned char E[10], unsigned char B[11], unsigned char M[7])
{
	int sayici = 0;
	///////////////////////////////////////////// PUSULA DATASI ///////////////////////////////////////////////////////////
	for(sayici = 0; sayici<3; sayici++){
		if(P[sayici] == NULL)																												{ veriPaketi[sayici] = '0';	continue;	}
		else																																					{	veriPaketi[sayici] = P[sayici];	}	}
	veriPaketi[sayici++] = 0x2F;
	///////////////////////////////////////////// ENLEM  DATASI ///////////////////////////////////////////////////////////
	for(int i=0; i<10;	i++,sayici++){
		if(E[i] == NULL)																														{ veriPaketi[sayici] = '0';	continue;	}
		else																																					{	veriPaketi[sayici] = E[i];	}	}	
	veriPaketi[sayici++] = 0x2F;	
	///////////////////////////////////////////// BOYLAM  DATASI ///////////////////////////////////////////////////////////
	for(int i=0; i<11;	i++,++sayici){
		if(B[i] == NULL)																														{ veriPaketi[sayici] = '0';	continue;	}
		else																																					{	veriPaketi[sayici] = B[i];	}	}	
	veriPaketi[sayici++] = 0x2F;
	//////////////////////////////////////////// ENCODER  DATASI ///////////////////////////////////////////////////////////
	for(int i=0; i<7;	i++,sayici++){
		if(M[i] == NULL)																														{ veriPaketi[sayici] = '0';	continue;	}
		else																																					{	veriPaketi[sayici] = M[i];	}	}	
	veriPaketi[sayici] = 0x0A;

}


void parcala_Gelen_Arayuz(char dizi[20])
{
	
	double basamak_pusula, basamak_encoder;
	int slash_Index = 0, s_Index = 0, enkoder_eleman, pusula_eleman;
	
	for(int i = 0; i<20; i++){
		if(dizi[i] == '/')												{							slash_Index = i;						}
		
		else if(dizi[i] == 'S')										{							  s_Index = i;							}}
		
	pusula_eleman = slash_Index - 1;	
	for(int j = 0; j<pusula_eleman; j++)									{		 basamak_pusula  += ustel(10,j) * (dizi[slash_Index-(j+1)]-48);			}
		
	enkoder_eleman = (s_Index - 1) - (slash_Index);
	for(int j = 0; j<enkoder_eleman; j++)									{	   basamak_encoder += ustel(10,j) * (dizi[(s_Index)-(j+1)]-48);			  }
		
	gelen_Pusula  = basamak_pusula;
	gelen_Encoder = basamak_encoder;
}

int parcala_Pusula(unsigned char dizi[3])
{
		int pusula;
		for(int i = 0; i<3; i++)														{								pusula +=	ustel(10,i)	* (dizi[2-i]-48);									}
		return pusula;
}

int ustel(int taban, int ust)
{
	int sayi = 1;
	for(int i = 0; i<ust; i++)												{							sayi *= taban;						}
	return sayi;
}

void tb_ileri(void)
{
		GPIO_SetBits(GPIOD,GPIO_Pin_1);
		GPIO_SetBits(GPIOD,GPIO_Pin_5);
		GPIO_ResetBits(GPIOD,GPIO_Pin_3);
}

void tb_dur(void)
{
		GPIO_ResetBits(GPIOD,GPIO_Pin_1);
		GPIO_SetBits(GPIOD,GPIO_Pin_3);
		GPIO_SetBits(GPIOD,GPIO_Pin_5);
}

