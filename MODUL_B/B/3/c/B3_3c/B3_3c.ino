#include <LiquidCrystal.h>	// podłączamy bibliotekę

  float temp;			// tworzymy zmienną typu float do przechowywania i pracy z
  float tempK;		// liczbami zmiennoprzecinkowymi 
float tempF;
float tmax=-100.0;		// tworzymy zmienną typu float, wartość max. temperatury
float tmin=100.0;		// tworzymy zmienną typu float, wartość min. temperatury

LiquidCrystal lcd(7, 8, 9, 10, 11, 12);	//definiujemy zmienną lcd, przez którą będziemy się
						//komunikować z modułem; podajemy do których
						//pinów podłączyliśmy się w Arduino

byte newChar[8] = {B11100, B10100, B11100, B00000, B00000, B00000, B00000, B00000};
					// definiujemy znak stopnia w celu wyświetlenia na lcd
void setup()				// początkowa konfiguracja – część przygotowująca układ do 
{					// działania
lcd.createChar(1, newChar);		// przypisanie wcześniej zdefiniowanego znaku do 0
lcd.begin(16, 2);
}

void loop()				// główna pętla
{
temp = (analogRead(0)*5/1024.0);	// przypisanie wartości odczytanej z wej. analogowego
temp = temp - 0.5;			//(0) i przeliczenie na napięcie (*) i podzielone przez
temp = temp / 0.01;			// dokładność przetwornika A/C (**), skalujemy do 0°C
tempK=temp+273,15;		// (***)otrzymaną różnicę dzielimy przez 10mV na stopień
tempF= (1.8*temp)+32;		// przeliczenia na inne jednostki
if (temp>tmax)			// wywołanie funkcji warunkowej sprawdzającej czy zmienna 
					// temp jest większa od tmax; jeśli tak to wchodzimy w pętle
tmax=temp;				// przypisanie wartości temp do tmax
if (temp<tmin)			// analogicznie sprawdzamy tmin (temp minimalną)
tmin=temp;				// przypisanie wartości
lcd.setCursor(0, 1);			// ustawienie kursora, w zadanej pozycji
lcd.print("   Temp= ");		// wyświetlenie komunikatu Temp
lcd.print(temp);			// wyświetlenie wartości zmiennej temp
lcd.write(1);				// wyświetlenie wcześniej zdefiniowanego znaku
lcd.setCursor(0, 0);			// ustawienie kursora w zadanej pozycji
lcd.print("T- ");			// wyświetlenie tekstu T- (temp minimalna)
lcd.print(tmin);			// wyświetlenie zmiennej tmin
lcd.write(1);				// wyświetlenie wcześniej zdefiniowanego znaku
lcd.setCursor(8, 0);			// ustawienie kursora w zadanej pozycji
lcd.print("T+ ");			//  wyświetlenie tekstu T+ (temp maksymalna)
lcd.print(tmax);			// wyświetlenie zmiennej tmax
lcd.write(1);				// wyświetlenie wcześniej zdefiniowanego znaku
delay(3500);			// poczekaj 3500ms = 3,5 s
lcd.clear();				// wyczyść wyświetlacz LCD
lcd.setCursor(0, 0);			// ustaw kursor
lcd.print("Temp.K= ");		// wyświetl tekst
lcd.print(tempK);			// wyświetl obliczoną wartość temp
lcd.print("K");			// wyświetl tekst
lcd.setCursor(0, 1);			// ustaw kursor
lcd.print("Temp.F= ");		// wyświetl tekst
lcd.print(tempF);			// wyświetl obliczoną wartość tempF
lcd.write(1);				// wyświetl znak stopnia
lcd.print("F");			// wyświetl tekst
delay(2800);			// oczekuj 2800ms = 2,8s
lcd.clear();				// wyczyść LCD
} 
