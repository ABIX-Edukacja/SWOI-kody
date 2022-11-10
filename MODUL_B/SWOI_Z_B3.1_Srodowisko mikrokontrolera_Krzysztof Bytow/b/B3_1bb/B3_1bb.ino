void setup()		// początkowa konfiguracja – część przygotowująca układ do  działania
{ 			
Serial.begin(9600);		// ustawienie prędkości komunikacji
for (int i=4; i<=6;i++) 		// pętla for
{
pinMode(i,OUTPUT);		// ustawienie pinu jako wyjście
digitalWrite(i,LOW);		// ustawienie stanu niskiego
}
}

void loop() 			// główna pętla
{
  int x =random(200,1000);		// przypisanie wartości losowej do x
  for (int i=4; i<=6;i++)		// pętla for
  {
  digitalWrite(i,HIGH);		// ustawienie stanu wysokiego
  delay(x);				// czekaj wartość x 
  digitalWrite(i,LOW);		// ustawienie stanu niskiego
  }
  for (int i=5; i>3;i--)		// pętla for
  {
  digitalWrite(i,HIGH);		// ustawienie stanu wysokiego
  delay(x);				// czekaj wartość x 
  digitalWrite(i,LOW);		// ustawienie stanu niskiego
  }
}

