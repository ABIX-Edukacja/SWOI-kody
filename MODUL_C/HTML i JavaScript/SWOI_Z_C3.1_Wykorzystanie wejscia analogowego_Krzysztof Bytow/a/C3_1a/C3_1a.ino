int i;

void setup()			// początkowa konfiguracja – część przygotowująca 
{				// układ do działania
  for (i=0; i<14; i++)		// w pętli ustawiamy piny jako wyjścia i ustawiamy stan niski
  pinMode(i, OUTPUT);
  digitalWrite(i,LOW);
}
void loop()			// główna pętla
{				// tworzymy zmienną j i przypisujemy
 int j=analogRead(0)/93;	// jej wartość odczytaną z wej. analogowego
 for (int x=1;x<=10;x++)	// w pętli zapalamy i gasimy diody
 if (x <= j)			// funkcja warunkowa
 {
 digitalWrite(x,HIGH);		// ustaw stan wysoki 
 }
 else
{
 digitalWrite(x,LOW);		// ustaw stan niski
}
delay(100);			// czekaj wyznaczony czas 
}
