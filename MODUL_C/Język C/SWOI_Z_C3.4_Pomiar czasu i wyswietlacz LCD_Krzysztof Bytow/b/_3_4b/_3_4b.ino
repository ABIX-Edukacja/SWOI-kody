#include <LiquidCrystal.h>			// biblioteka LCD	
int sek = 0;					// zmienna typu intiger z wartością początkową 0
int minuty = 0;				// zmienna typu intiger z wartością początkową 0		
int godziny =0;				// zmienna typu intiger z wartością początkową 0
int dni = 0;					// zmienna typu intiger z wartością początkową 0	
LiquidCrystal lcd(7,8,9,10,11,12);		//definiujemy zmienną lcd, przez którą będziemy się 						//komunikować z modułem; podajemy do których 
						//pinów podłączyliśmy się w Arduino 	
void setup()					// parametry przygotowawcze
{
lcd.begin(16,2);				// parametry wyświetlacza		
}

void loop()					// główna pętla
{
 lcd.setCursor(8,0);				// ustawienie kursora
 lcd.print ("Godzin ");			// wyświetlenie tekstu
 lcd.print (godziny);				// wyświetlenie wartości przypisanej do godziny
 lcd.print (" ");				// wyświetlenie tekstu -spacja
 lcd.setCursor (0,0);				// ustaw kursor
 lcd.print ("DNI ");				// wyświetlenie tekstu
 lcd.print (dni);				// wyświetlenie wartości przypisanej do dni
 if ( minuty == 60)				// pętla -wejście gdy spełniony zostaje warunek
{					
 delay (32);					// czekaj 32ms = 0,32s
 minuty = 0;					// przypisz wartość 0
 godziny ++;					// zwiększ godziny
 }
 if (godziny> 23)				// wywołanie instrukcji warunkowej -wejście gdy 
 {						// spełniony zostaje warunek
 dni++;					// zwiększ dni o 1
 godziny = 0;					// przypisz wartość 0
 }

 lcd.setCursor (0,1);				// ustaw kursor			
 lcd.print (minuty);				// wyświetlenie wartości przypisanej do minuty
 lcd.print (" min ");				// wyświetlenie tekstu
 lcd.setCursor (8,1);				// ustaw kursor
 lcd.print (sek);				// wyświetlenie wartości przypisanej do sek
 lcd.print (" SEC ");				// wyświetlenie tekstu
 if (sek >59)					// analogicznie jak wyżej	
 {
 minuty ++;					// zwiększ minuty			
 sek = 0;					// przypisz 0
 delay (58);					// czekaj 58ms – 0,58s
 }
 if (sek < 60)					// analogicznie jak wyżej		
 {
 delay (988);					// czekaj 988ms=0,988 s
 sek ++;					// zwiększ sek
 }
}	

