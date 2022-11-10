unsigned long czas;			//definowanie zmiennych wykorzystanych w kodzie

void setup()
{
  for (int i=5;i<=12;i++)		// w pętli ustawiamy piny od 5 do 12 jako wyjścia i ustawiamy stan niski
  {
    pinMode(i, OUTPUT);
    digitalWrite(i,LOW);
  }
  pinMode(8,INPUT);		// ustawiamy Pin 8 jako wejście
  digitalWrite(8,HIGH);		//  pullup 
  digitalWrite(10,HIGH);		// zapalamy diody wpięte do Pinu 10 i 5
  digitalWrite(5,HIGH);
}
void loop()
{
  if (digitalRead(8)==LOW && (millis() - czas) > 5000)		 // funkcja warunkowa
  {
  przejscie();					// gdy zostanie wciśnięty button wywołanie funkcji przejście
  }
}

void przejscie()
{
  delay(800);				// czekaj wyznaczony czas 
  off();					// wywołanie funkcji gaszącej diody
  digitalWrite(6,HIGH);
  delay(2000);				// czekaj 2 sekundy
  off();					// wywołanie funkcji gaszącej diody
  digitalWrite(7,HIGH);
  delay(2000);				// czekaj wyznaczony czas 
  digitalWrite(10,LOW);
  digitalWrite(11,HIGH);
  delay(5000);				// czekaj wyznaczony czas 
  for (int x=0;x<10;x++)			// mruganie diody zielonej dla pieszych
  {
   digitalWrite(11,HIGH);
   delay(250);				// czekaj wyznaczony czas 
   digitalWrite(11,LOW);
   delay(250);				// czekaj wyznaczony czas 
  }
  digitalWrite(10,HIGH);
  delay(3000);				// czekaj wyznaczony czas 
  digitalWrite(6,HIGH);
  delay(2000);				// czekaj wyznaczony czas 
  off();					// wywołanie funkcji gaszącej diody
  digitalWrite(5,HIGH);
  czas=millis(); 			// millis() zwraca liczbę millisekund od czasu jak Arduino wykonuje
}						// bieżący program
	
void off()					// gasimy diody od pinu 5 do 7 ustawiając stan niski
{
digitalWrite(5,LOW);
digitalWrite(6,LOW);
digitalWrite(7,LOW);
}
