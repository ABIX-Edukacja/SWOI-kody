#include <LiquidCrystal.h>			// biblioteka LCD	
#include <Time.h>				// biblioteka time	

LiquidCrystal lcd(7,8,9,10,11,12);		//definiujemy zmienną lcd, przez którą będziemy się 						//komunikować z modułem; podajemy do których 
						//pinów podłączyliśmy się w Arduino 	
void setup()					// parametry przygotowawcze
{
setTime(15,20,20,15,8,2012); 		// ustawiamy godzinę i datę
Serial.begin(9600);				
}								
								
void loop()					// główna pętla				
{ 
unsigned long czas = now();		// przypisanie aktualnego czasu 
while(czas == now());
zegar();					// wywołanie funkcji zegar
}

void wyswietl(byte i)					
{
lcd.print(":");						
if(i < 10)					
lcd.print('0');					
lcd.print(i,DEC);				
}

void zegar()
{	
lcd.clear();				// czyszczenie LCD	
lcd.begin(16,2);			// parametry wyświetlacza				
lcd.setCursor(3,0);			// ustawienie kursora na wyświetlaczu LCD		

if(day() <10)		
lcd.print('1');					
lcd.print(day(),DEC);		
lcd.print("/");					

if(month() <10)			
lcd.print('0');					
lcd.print(month(),DEC);		
lcd.print("/");					
lcd.print(year(),DEC);	

if(hour() <10)			
lcd.setCursor(5,1);			// ustawienie kursora na wyświetlaczu LCD	
lcd.setCursor(4,1);			// ustawienie kursora na wyświetlaczu LCD	
lcd.print(hour(),DEC);		
wyswietl(minute());			// wywołanie funkcji wyświetl
wyswietl(second());			// wywołanie funkcji wyświetl
}
