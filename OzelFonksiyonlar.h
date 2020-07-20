#ifndef OzelFonksiyonlar_h
#define OzelFonksiyonlar_h

/* Includes ------------------------------------------------------------------*/
#include <stdint.h>
#include <string.h>


/*	Degiskenler	------------------------------------- */
extern int sayiyi_Parcala_Byte[7];
extern int convertToByte[20];



/*				7 Basamakli bir sayiyi par�alayan bir fonksiyondur.
 *
 *						Return degeri 7 elemanli integer tipidir.		
 *
 * 				G�nderilecek verinin byte sayisi degismemesi i�in,	
 * 				Par�alanan sayilar saga dayali bosta kalan her bir 
 * 							elaman i�in 0 degeri atanmaktadir
 *
 *						�rnek iki �ikti asagidaki gibidir..
 * 
 *									1.�ikti -> 0000056
 *  								2.�ikti -> 0001978
 *
 */

void sayiyi_Parcala(uint32_t sayi);

/*	Istenilen bir sayiyi OCTAL olarak par�alayan bir fonksiyondur.
 *
 *			Return degeri par�alanan sayinin basamak sayisidir ve,		
 *						Geri d�n�s integer tipindedir.
 *
 *	�rnek iki �ikti asagidaki gibidir..
 * 
 *	1.�ikti i�in girilen sayi 56   -> 0000056
 *  1.�ikti i�in girilen sayi 1978 -> 0001978
 *
 *			!!	DAHA SONRA G�NCELLENECEK !!
 */
 
int Convert_ToByte(uint32_t sayi);

/*						Gelen 473 Byte'lik GPS Datasinin
 *
 *			$GPGGA data bilgisinden sonra gelen enlem ve boylam
 *			data bilgilerini ayristiran bir ayirici fonksiyondur.   
 *						Geri d�n�s unsigned char tipindedir.
 *
 *					..�rnek iki �ikti asagidaki gibidir..
 * 
 *							1.Enlem �ikti  -> 41XX.XXXXX
 *  						1.Boylam �ikti -> 00831.54761
 *
 */

void get_Lat_Lon(unsigned char gpsGelen[]);

/*						I�ine g�nderilen '.' ile ayrilmis unsigned char diziyi 
 *							Par�alayarak double bir sayiya �eviren fonksiyondur						
 *			
 *									Geri d�n�s double tipindedir.
 *
 *								..�rnek iki �ikti asagidaki gibidir..
 * 
 *				1.Giris i�in �ikti '8','7','0','.','1','2','3' -> 870.123
 *  			2.Giris i�in �ikti '0','3','2','.','1','2','0' -> 32.12
 *													2.77 ms return
 */		

double convertUcharArrayToFloat(unsigned char dizi[],int noktaIndex,int son_Nokta);

/*				Sens�rlerden alinan datalari uzunluklarina gore '/' char karakteri
 *				le birbirlerinden ayirarak bir dizi de toplayan fonksiyondur
 *												Geri d�n�s degeri yoktur
 *									
 *											Dizinin eleman sayisi 35 dir
 *													
 * 		115.500 baudrate'de	1 Stop biti parity none seklinde tanimlanan UART protokol�nde
 *										b�t�n verinin aktarimi 3.05 ms s�rmektedir
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
 *																		�stel Fonksiyon
 *
 *	Girilen taban degerini , ust paramteresi kadar art arda �arparak toplayan bir fonksiyondur.
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

