#include <OneWire.h>				// podłączamy bibliotekę
#include <DallasTemperature.h>			// podłączamy bibliotekę
#define liczba_czujnikow 2		
byte adresy [liczba_czujnikow][8];	
byte urzadzen;
					
OneWire linia_danych(7);		   		 // tworzymy obiekt OneWire, z użyciem 
DallasTemperature czujniki(&linia_danych);	//określonego pinu wskazujemy OneWire 
			       
void setup()				
 {
  Serial.begin(9600);					// ustawienie prędkości komunikacji
  czujniki.begin();					// uruchamiamy bibliotękę
  urzadzen = wyszukaj_adres(); 	
  for (byte i=0; i < urzadzen; i++) 
  czujniki.setResolution(adresy[i], 10);		
 }

byte wyszukaj_adres() 
{
  byte j=0;                                      
  while ((j < liczba_czujnikow) && (linia_danych.search(adresy[j]))) 
{        
    j++;
  }
  for (byte i=0; i < j; i++)
 {
    Serial.print("Adres czujnika numer ");		// wyświetlenie tekstu
    Serial.print(i);  					// wyświetlenie tekstu
    Serial.print(": ");   				// wyświetlenie tekstu
    adres(adresy[i]);               
  }
  Serial.print("\r\n");					// wyświetlenie tekstu
  return j ;          
}

void adres(DeviceAddress addr)
 {
  byte i;
  for( i=0; i < 8; i++) 
{               
      Serial.print("0x");
      if (addr[i] < 16)
 {
        Serial.print('0');            
      }
      Serial.print(addr[i], HEX);             
      if (i < 7)
    {
        Serial.print(", ");			// wyświetlenie tekstu
      }
    }
  Serial.println("");				// wyświetlenie tekstu
}

void loop()					// główna pętla
 {
  delay(2000);				// czekaj wyznaczony czas
  czujniki.requestTemperatures();      
  for (byte i=0; i < urzadzen; i++)
  {
    Serial.print("Czujnik ");			// wyświetlenie tekstu
    Serial.print(i);				// wyświetlenie tekstu
    Serial.print(": ");				// wyświetlenie tekstu
    wyswietl(adresy[i]);
    Serial.print("\n\r");			// wyświetlenie tekstu
  }
  Serial.print("\n\r");				// wyświetlenie tekstu
}

void wyswietl(DeviceAddress addr)
 {
  float tempC = czujniki.getTempC(addr);         
  if (tempC == -127.00)
 {
    Serial.print("Error !!!");			// wyświetlenie tekstu
  } 

else 
 {
    Serial.print(tempC);   			// wyświetlenie tekstu
    Serial.print(" C");				// wyświetlenie tekstu
  }}
