#include <LiquidCrystal.h>			// podłanczamy bibliotekę
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);		//definiujemy zmienną lcd, przez którą będziemy się 							//komunikować z modułem; podajemy do których 
						//pinów podłączyliśmy się w Arduino 
void setup()					
{
 lcd.begin(16, 2);
}
void loop()					// główna pętla
{
 lcd.clear();					// czyścimy znaki na wyświetlaczu
 lcd.print(" !!! SWOI !!!");			// wyświetlamy napis
 lcd.setCursor(4, 1);				// ustawiamy kursor kolumna (wartości od 0 do 16)
						// wiersz (wartości od 0 do 1)
 lcd.print(" Witaj ");				// wyświetlamy napis
 delay(2000);					// czekaj 2 sekundy
}
