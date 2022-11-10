void setup() 			// początkowa konfiguracja – część przygotowująca 
{					// układ do działania
    pinMode(8, OUTPUT);		// ustawienie pinu jako wyjście
}
void loop()				// główna pętla
{
     tone(8, 2193, 4);			// generowanie przebiegu prostokątnego z określoną częstotliwością 					// tone(pin, częstotliwość, czas trwania)
    delayMicroseconds(1000);	// czekaj wyznaczony czas
    noTone(8);			// zatrzymanie generowania przebiegu na pinie 8
    delayMicroseconds(1000);	// czekaj wyznaczony czas
}
