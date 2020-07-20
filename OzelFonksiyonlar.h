#ifndef OzelFonksiyonlar_h
#define OzelFonksiyonlar_h

/* Includes ------------------------------------------------------------------*/
#include <stdint.h>
#include <string.h>


/*	Degiskenler	------------------------------------- */
extern int sayiyi_Parcala_Byte[7];
extern int convertToByte[20];



/*				7 Basamakli bir sayiyi parçalayan bir fonksiyondur.
 *
 *						Return degeri 7 elemanli integer tipidir.		
 *
 * 				Gönderilecek verinin byte sayisi degismemesi için,	
 * 				Parçalanan sayilar saga dayali bosta kalan her bir 
 * 							elaman için 0 degeri atanmaktadir
 *
 *						Örnek iki çikti asagidaki gibidir..
 * 
 *									1.Çikti -> 0000056
 *  								2.Çikti -> 0001978
 *
 */

void sayiyi_Parcala(uint32_t sayi);

/*	Istenilen bir sayiyi OCTAL olarak parçalayan bir fonksiyondur.
 *
 *			Return degeri parçalanan sayinin basamak sayisidir ve,		
 *						Geri dönüs integer tipindedir.
 *
 *	Örnek iki çikti asagidaki gibidir..
 * 
 *	1.Çikti için girilen sayi 56   -> 0000056
 *  1.Çikti için girilen sayi 1978 -> 0001978
 *
 *			!!	DAHA SONRA GÜNCELLENECEK !!
 */
 
int Convert_ToByte(uint32_t sayi);

/*						Gelen 473 Byte'lik GPS Datasinin
 *
 *			$GPGGA data bilgisinden sonra gelen enlem ve boylam
 *			data bilgilerini ayristiran bir ayirici fonksiyondur.   
 *						Geri dönüs unsigned char tipindedir.
 *
 *					..Örnek iki çikti asagidaki gibidir..
 * 
 *							1.Enlem Çikti  -> 41XX.XXXXX
 *  						1.Boylam Çikti -> 00831.54761
 *
 */

void get_Lat_Lon(unsigned char gpsGelen[]);

/*						Içine gönderilen '.' ile ayrilmis unsigned char diziyi 
 *							Parçalayarak double bir sayiya çeviren fonksiyondur						
 *			
 *									Geri dönüs double tipindedir.
 *
 *								..Örnek iki çikti asagidaki gibidir..
 * 
 *				1.Giris için Çikti '8','7','0','.','1','2','3' -> 870.123
 *  			2.Giris için Çikti '0','3','2','.','1','2','0' -> 32.12
 *													2.77 ms return
 */		

double convertUcharArrayToFloat(unsigned char dizi[],int noktaIndex,int son_Nokta);

/*				Sensörlerden alinan datalari uzunluklarina gore '/' char karakteri
 *				le birbirlerinden ayirarak bir dizi de toplayan fonksiyondur
 *												Geri dönüs degeri yoktur
 *									
 *											Dizinin eleman sayisi 35 dir
 *													
 * 		115.500 baudrate'de	1 Stop biti parity none seklinde tanimlanan UART protokolünde
 *										bütün verinin aktarimi 3.05 ms sürmektedir
 *
 *  							1 byte'lik verinin aktarim hizi ise 0.086 ms'dir													
 */		

void veriPaketi_Olustur(unsigned char P[3], unsigned char E[10], unsigned char B[11], unsigned char M[7]);

/*				
 *				
 *												
 *									
 *											
 *													
 * 		
 *										
 *
 *  							
 */		
 
void parcala_Gelen_Arayuz(char dizi[20]);

/*				
 *																		Üstel Fonksiyon
 *
 *	Girilen taban degerini , ust paramteresi kadar art arda çarparak toplayan bir fonksiyondur.
 * 
 */	

int ustel(int taban, int ust);

/*				
 *				
 *												
 *									
 *											
 *													
 * 		
 *										
 *
 *  							
 */

int parcala_Pusula(unsigned char dizi[3]);
/* 
 *			Motor 1 Ileri																	
 */	

void tb_ileri(void);
	
/* 
 *			Motor 1 Dur														
 */	
	
void tb_dur(void);
#endif

