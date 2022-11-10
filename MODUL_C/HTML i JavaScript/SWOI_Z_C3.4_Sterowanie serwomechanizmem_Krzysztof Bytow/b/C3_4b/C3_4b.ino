#include <Servo.h>
int s1=5;			// przyznanie etykiety dla numeru pinu
int s2=7;			// przyznanie etykiety dla numeru pinu
int i=0;			// tworzymy zmienną typu intiger 
Servo s;			// definiujemy zmienną s, przez którą będziemy się komunikować

void setup()			// początkowa konfiguracja – część przygotowująca
{				// układ do działania
  Serial.begin(9600);
  s.attach(6);			// deklarujemy pod który pin podłączyliśmy serwomechanizm   
  s.write(i);			// zapisujemy wartość do serwomechanizmu (kąt)
  pinMode(s1, INPUT);	// ustawienie pinu przycisków jako wejścia
  digitalWrite(s1,HIGH);	// włączenie wewnętrznych rezystorów podciągających
  pinMode(s2, INPUT);	// ustawienie pinu przycisków jako wejścia
  digitalWrite(s2,HIGH);	// włączenie wewnętrznych rezystorów podciągających
}

void loop()			// główna pętla
{
   if(digitalRead(s1)==LOW)		// sprawdzamy czy został wduszony button
  {
 i+=5;
 if(i>60)
 {
 i=60;
 }}
  if(digitalRead(s2)==LOW)		// sprawdzamy czy został wduszony button
{  
  i-=5;  
 if(i<0)
 {
   i=0;
 }}
 s.write(i);				// zapisujemy wartość do serwomechanizmu (kąt)
 int j=s.read();			// odczyt wartości serwomechanizmu, a następnie 
 Serial.println(j);			// wysłanie i wyświetlenie na monitorze
 delay(25);				// czekaj wyznaczony czas
}
 

