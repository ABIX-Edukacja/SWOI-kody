float temp;			// tworzymy zmienną typu float do przechowywania i pracy z
				// liczbami zmiennoprzecinkowymi 
void setup()			// początkowa konfiguracja – część przygotowująca układ do 
{				// działania
Serial.begin(9600);		// ustawienie prędkości komunikacji
}

void loop()				// główna pętla
{
temp = (analogRead(0)*5/1024.0);	// przypisanie wartości odczytanej z wej. analogowego 
temp = temp - 0.5;			//(0) i przeliczenie na napięcie (*) i podzielone przez
temp = temp / 0.01;			// dokładność przetwornika A/C (**), skalujemy do 0°C
					// (***)otrzymaną różnicę dzielimy przez 10mV na stopień
Serial.println(temp);			// wysłanie i wyświetlenie do komputera temperatury
delay(1500);				// czekaj 1,5 sekundy
} 
