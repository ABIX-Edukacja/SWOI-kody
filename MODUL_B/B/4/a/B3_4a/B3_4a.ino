int d1=8;				// przyznanie etykiety dla numeru pinu
int d2=9;				// przyznanie etykiety dla numeru pinu
int d3=10;				// przyznanie etykiety dla numeru pinu
int d4=11;				// przyznanie etykiety dla numeru pinu
int d5=12;				// przyznanie etykiety dla numeru pinu
int d6=13;				// przyznanie etykiety dla numeru pinu
int s1=2;					// przyznanie etykiety dla numeru pinu

void off()				// funkcja off – gasi diody
{
for (int i=8; i<=13;i++)			// pętla for
digitalWrite(i,LOW);			// ustaw stan niski dla wyjść i
}

void setup()				// początkowa konfiguracja – część przygotowująca układ do 
{					// działania
Serial.begin(9600);			// ustawienie prędkości komunikacji
for (int i=8; i<=13;i++)			// pętla for 
{
pinMode(i,OUTPUT);			// ustawienie „i” pinów jako wyjście
digitalWrite(i,LOW);			// ustaw stan niski
}
pinMode(s1,INPUT);			// ustawienie „i” pinów jako wejście
digitalWrite(s1,HIGH);			// ustaw stan wysoki
}

void loop()				// główna pętla
{
int y=random(7,14);			// przypisz losową wartość z przedziału
digitalWrite(y,HIGH);			// ustaw stan wysoki
delay(180);				// czekaj 180ms
digitalWrite(y,LOW);			// ustaw stan niski
if (digitalRead(s1) == LOW)		// instrukcja warunkowa
{
Serial.println("wduszono button");		// wyświetl tekst
int x = random(8,14);			// przypisz do x wartość losową z przedziału
for ( int z=8; z<=x;z++)			// pętla for

{
digitalWrite(z,HIGH);			// ustaw stan wysoki na wyjściu
Serial.println(x);				// wyświetl wartość x
Serial.println(z);				// wyświetl wartość y
}
delay(1200);				// czekaj 1,2 sekundy
}
off();					// skocz do funkcji off
}
