#include <LiquidCrystal.h>			// podłączamy bibliotekę
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);	//definiujemy zmienną lcd, przez którą będziemy się 							//komunikować z modułem; podajemy do których 
byte znak[8] = 
{
	B11100,
	B10100,
	B11100,
	B00000,
	B00000,
	B00000,
	B00000,
	B00000
};
void setup()					// początkowa konfiguracja – część przygotowująca układ do 
{						// działania
 lcd.createChar(1, znak);
 lcd.begin(16, 2);
}
void loop() 					// główna pętla
{
 lcd.print("  !!! SWOI !!!");			//wyświetlamy napis SWOI
 lcd.setCursor(0, 1);				//ustawiamy kursor w pozycji (kolumna, wiersz 0 lub 1)
 lcd.print("  Temp=38");			// wyświetlamy napis
 lcd.write(1);				// wyświetlenie wcześniej zdefiniowanego znaku
 delay(3000);  				// odczekanie 3 sekund
 lcd.clear();					// wyczyszczenie wyświetlacza
 lcd.print("  Test ");				// wyświetlenie napisu Test
 delay(1500);  				// odczekanie 1,5 sekundy
 lcd.clear();					// wyczyszczenie wyświetlacza
 } 
