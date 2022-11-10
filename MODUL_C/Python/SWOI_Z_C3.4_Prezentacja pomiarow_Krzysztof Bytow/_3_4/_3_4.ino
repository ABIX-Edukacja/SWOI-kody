int buzzer=2;				// przyznanie etykiety dla numeru pinu
float temp;				// tworzymy zmienną typu float
int red=5;			// przyznanie etykiety dla numeru pinu
int blue=6;			// przyznanie etykiety dla numeru pinu
int green=9;			// przyznanie etykiety dla numeru pinu
int s2=0;			// przypisanie zmiennej s2 wartości 0
void setup()			// początkowa konfiguracja – część przygotowująca układ do 
{				// działania
Serial.begin(9600);		// ustawienie prędkości komunikacji
pinMode(buzzer,OUTPUT);		// ustawienie pinu jako wyjście
for(int i=5;i<10;i++)		// w pętli ustawiamy porty Arduino jako wyjścia
{					
pinMode(i,OUTPUT);		// ustaw jako wyjście
}}

void loop()					// główna pętla
{
temp = (analogRead(0)*5/1024.0);	// przypisanie wartości odczytanej z wej. analogowego
temp = temp - 0.5;		//(0) i przeliczenie na napięcie (*) i podzielone przez
temp = temp / 0.01;		// dokładność przetwornika A/C (**), skalujemy do 0°C
Serial.println(temp);		// temp jest większa od tmax; jeśli tak to wchodzimy w pętle
if (temp>=0 && temp < 10)	// instrukcja warunkowa
 {				
s2=(temp*25.5);			// przypisz wartość s2
analogWrite(red,s2);			// ustaw wypełnienie na wartość s2 dla wyjścia red
delay(500);				// czekaj 500ms
off(0);					// funkcja off
 }

if (temp>=10 && temp < 20)		// instrukcja warunkowa	
 {
s2=((temp-10)*25.5);			// przypisz wartość s2
analogWrite(green,s2);			// ustaw wypełnienie na wartość s2 dla wyjścia green
delay(500);					// czekaj 500ms
off(0);						// funkcja off
}
if (temp>=20 && temp < 30)		// instrukcja warunkowa
 {
s2=((temp-20)*25.5);			// przypisz wartość s2
analogWrite(blue,s2);			// ustaw wypełnienie na wartość s2 dla wyjścia blue
delay(500);					// czekaj 500ms
off(0);						// funkcja off
 }

if (temp<0 || temp>=30)			// instrukcja warunkowa
 {
   off(0);					// funkcja off
   wlacz(750,500); 				// funkcja wlacz
   delay(500);					//czeka 500mc
 }} 

void wlacz(long x1, int x2)
{
x1 *= 1000;					// x1 = x1 * 1000
int dl = (1.0 / x2) * 1000000;
long czas = 0;				// zmienna typu long
while (czas < x1)				// pętla while
{
digitalWrite(buzzer,HIGH);			// ustaw stan wysoki dla wyjścia buzzer
delayMicroseconds(dl / 2);			// czekaj
digitalWrite(buzzer, LOW);			// ustaw stan niski dla wyjścia buzzer
delayMicroseconds(dl / 2);			// czekaj
czas += (dl);					// czas = czas+ dl
}}

void off(int s1)			//funkcja off gasi diody
{
  analogWrite(red,s1);		// ustaw wypełnienie na wartość s1 dla wyjścia red
  analogWrite(green,s1);		// ustaw wypełnienie na wartość s1 dla wyjścia green
  analogWrite(blue,s1);		// ustaw wypełnienie na wartość s1 dla wyjścia blue
}
