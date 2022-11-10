float x,y,z;				// tworzymy zmienną typu float do przechowywania i pracy z
					// liczbami zmiennoprzecinkowymi 
void setup()			// początkowa konfiguracja – część przygotowująca układ do 
{					// działania
  Serial.begin(9600);		// ustawienie prędkości komunikacji
}
void loop()			// główna pętla
{
  x=analogRead(0)*5/1024.0;	// przypisanie wartości odczytanej z wej. analogowego 
  y=analogRead(1)*5/1024.0;	// i przeliczenie na napięcie (*); podzielone przez dokładność
  z=analogRead(2)*5/1024.0;	// przetwornika analogowo cyfrowego
  Serial.println(x);			// wysłanie do komputera wartości x
  Serial.println(y);			// wysłanie do komputera wartości x
  Serial.println(z);			// wysłanie do komputera wartości x
  delay(2500);			// odczekanie 2,5 sekundy
  Serial.println("Nastepny pomiar");	// wysłanie komunikatu
  Serial.println("---------------");		// wysłanie komunikatu
}
