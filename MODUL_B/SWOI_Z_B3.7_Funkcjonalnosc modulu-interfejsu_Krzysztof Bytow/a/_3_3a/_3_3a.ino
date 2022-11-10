int dioda = 13; 			// przyznanie etykiety dla numeru pinu
int czas = 1000;			// tworzymy daną typu intiger 
int x=10;

void setup()				// początkowa konfiguracja – część przygotowująca 
{						// układ do działania
Serial.begin(9600); 			// ustawienie prędkości komunikacji
pinMode(dioda, OUTPUT); 		// ustawienie pinu jako wyjście
}

void loop()					// główna pętla
{
Serial.println("Witaj - Arduino");		// wyświetlenie tekstu
delay(500);				// czekaj 500ms = 0,5 s
Serial.print("Przypisana wartosc dla i = ");	// wyświetl tekst
delay(500);				// czekaj 500ms = 0,5 s
Serial.println(x);				// wyświetl wartość x
delay(500);				// czekaj 500ms = 0,5 s
digitalWrite(dioda, HIGH); 		// zapalenie diody – stan wysoki
Serial.println("Dioda swieci");		// wyświetlenie tekstu
delay(3000); 				// oczekiwanie 3000ms = 3 sekundy
digitalWrite(dioda, LOW); 			// wyłączenie diody – stan niski
Serial.println("Dioda nieswieci");		// wyświetlenie tekstu
delay(1500); 				// oczekiwanie 1500ms = 1,5 sekundy
digitalWrite(dioda, HIGH); 		// zapalenie diody – stan wysoki
Serial.println("Dioda swieci");		// wyświetlenie tekstu
delay(czas); 				// oczekiwanie 1000ms = 1 sekunda
digitalWrite(dioda, LOW); 			// wyłączenie diody – stan niski
Serial.println("Dioda nieswieci");		// wyświetlenie tekstu
delay(500); 				// oczekiwanie 500ms = 0,5 sekundy
}
