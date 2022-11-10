#include <Ultrasonic.h>	// podłączamy bibliotekę
Ultrasonic miernik(3,4);	//definiujemy porty pod które podpięty jest czujnik

void setup()			// początkowa konfiguracja – część przygotowująca układ do
{				// początkowa konfiguracja – część przygotowująca układ do
  Serial.begin(9600);      	//rozpoczęcie komunikacji
}

void loop()				// główna pętla
{
int x=miernik.Ranging(CM);		// definiujemy zmienną x i przypisujemy jej wartość
Serial.print(x);				// wyświetl wartość na monitorze
Serial.println( "cm" );			// wyświetl tekst na monitorze
delay(1000);				//czekaj 1000ms
}
