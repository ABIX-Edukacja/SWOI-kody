#include <Servo.h>
int dioda1=5;			// przyznanie etykiety dla numeru pinu
int dioda2=7;			// przyznanie etykiety dla numeru pinu
int i=0;			// tworzymy zmienną typu intiger 
Servo s;			// definiujemy zmienną s, przez którą będziemy się komunikować
 
void setup()			// początkowa konfiguracja – część przygotowująca 
{				// układ do działania
  s.attach(6);			// deklarujemy pod który pin podłączyliśmy serwomechanizm       s.write(i);				// zapisujemy wartość do serwomechanizmu (kąt)
  pinMode(dioda1,OUTPUT);		// ustawienie pinu jako wyjście
  digitalWrite(dioda1,LOW);		// ustawienie na pinie stanu niskiego – dioda nie świeci
  pinMode(dioda2,OUTPUT);		// ustawienie pinu jako wyjście
  digitalWrite(dioda2,LOW);		// ustawienie na pinie stanu niskiego – dioda nie świeci
}
void loop()				// główna pętla
{
  for(i=0;i<=60;i=i+5)		// zmiana wartości i w pętli od 0 do 60
{  
  s.write(i);				// zapisujemy wartość do serwomechanizmu (kąt)
  digitalWrite(dioda1,HIGH);	// ustawienie na pinie stanu wysokiego – dioda świeci
  digitalWrite(dioda2,LOW);		// ustawienie na pinie stanu niskiego – dioda nie świeci
  delay(1500);			// czekaj wyznaczony czas
  }
  for(i=60;i>=0;i=i-5)		// zmiana wartości i w pętli od 60 do 0
{  
    s.write(i);				// zapisujemy wartość do serwomechanizmu (kąt)
    digitalWrite(dioda1,LOW);	// ustawienie na pinie stanu niskiego – dioda nie świeci
    digitalWrite(dioda2,HIGH);	// ustawienie na pinie stanu wysokiego – dioda świeci
    delay(1500);			// czekaj wyznaczony czas
 }
}
