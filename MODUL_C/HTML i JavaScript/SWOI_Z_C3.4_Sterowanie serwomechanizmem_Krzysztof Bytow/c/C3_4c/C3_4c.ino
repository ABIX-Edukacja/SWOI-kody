#include <Servo.h>
int i=0;		// tworzymy zmienną typu intiger 
Servo s;		// definiujemy zmienną s, przez którą będziemy się komunikować

void setup()			// początkowa konfiguracja – część przygotowująca
{				// układ do działania
  Serial.begin(9600);
  s.attach(6);			// deklarujemy pod który pin podłączyliśmy serwomechanizm   
  s.write(i);			// zapisujemy wartość do serwomechanizmu (kąt)
}

void loop()			// główna pętla
{
 i=analogRead(0);		// przypisanie wartości odczytanej z wejścia analogowego
 i=map(i,0,1023,0,60);	// zmiana zakresu z jednego na inny z 0-1023 na 0-60
 s.write(i);			// zapisujemy wartość do serwomechanizmu (kąt)
 int j=s.read();		// odczyt wartości serwomechanizmu, a następnie
 Serial.println(j);		// wysłanie i wyświetlenie na monitorze
 delay(25);			// czekaj wyznaczony czas
}
