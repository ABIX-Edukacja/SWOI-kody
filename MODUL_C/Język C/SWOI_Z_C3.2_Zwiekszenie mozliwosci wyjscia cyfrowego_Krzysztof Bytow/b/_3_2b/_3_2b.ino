int diody = 3;               			// diody podłączone do pinu 3

void setup()                  			// początkowa konfiguracja - część przygotowująca
{
  pinMode(diody, OUTPUT);     		// ustaw jako wyjście
}

void loop()                  			// główna pętla programu
{
  digitalWrite(diody, HIGH);   		// ustaw stan wysoki
  delay(5000);                  			// czeaj 5 sekund
  digitalWrite(diody, LOW);    		// ustaw stan niski
  delay(2500);                 			// czekaj 2,5 sekundy
  digitalWrite(diody, HIGH);   		// ustaw stan wysoki
  delay(4000);                  			// czeaj 4 sekundy
  digitalWrite(diody, LOW);    		// ustaw stan niski
  delay(1500);                  			// czekaj 1,5 sekundy
}
