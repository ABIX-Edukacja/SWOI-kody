#include <OneWire.h>	// podłączamy bibliotekę
#include <DallasTemperature.h>	// podłączamy bibliotekę

OneWire linia_danych(7);		// tworzymy obiekt OneWire, z użyciem określonego pinu
DallasTemperature czujnik(&linia_danych); 	// wskazujemy OneWire

void setup()
{
  Serial.begin(9600);					// ustawienie prędkości komunikacji
  czujnik.begin();					// uruchamiamy bibliotekę
}
void loop()						// główna pętla
{
  czujnik.requestTemperatures();			// wysłanie polecenia pobrania temperatury
  Serial.print("Czujnik numer 1: ");			// wyświetlenie tekstu
  Serial.println(czujnik.getTempCByIndex(0));	// wyświetlenie tekstu - temperatury
  Serial.print("\r\n");					// wyświetlenie tekstu
  delay(2000);					// czekaj wyznaczony czas
}
