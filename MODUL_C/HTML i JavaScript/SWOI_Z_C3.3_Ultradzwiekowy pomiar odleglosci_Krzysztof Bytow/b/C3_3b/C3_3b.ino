#include <Ultrasonic.h>		// podłączamy bibliotekę
#include <LiquidCrystal.h>		// podłączamy bibliotekę
LiquidCrystal lcd(8, 9, 10, 11, 12, 13);	//definiujemy zmienną lcd, przez którą będziemy się
		//komunikować z modułem; podajemy do których pinów podłączyliśmy się w Arduino
Ultrasonic miernik(3,4);		//analogicznie jak wyżej
int dioda1=5;				//przyznanie etykiety dla numeru pinu
int dioda2=6;				//przyznanie etykiety dla numeru pinu
int dioda3=7;				//przyznanie etykiety dla numeru pinu

void setup()			
{				
  Serial.begin(9600);
  lcd.begin(16, 2);			// definiowanie LCD 16 znaków, 2 wiersze
  pinMode(dioda1,OUTPUT);		// ustawienie pinu jako wyjście
  digitalWrite(dioda1,LOW);		// ustawienie stanu niskiego – dioda nie świeci
  pinMode(dioda2,OUTPUT);		// ustawienie pinu jako wyjście
  digitalWrite(dioda2,LOW);		// ustawienie stanu niskiego – dioda nie świeci
  pinMode(dioda3,OUTPUT);		// ustawienie pinu jako wyjście
  digitalWrite(dioda3,LOW);		// ustawienie stanu niskiego – dioda nie świeci
}

void loop()				// główna pętla
{
int x=miernik.Ranging(CM);		// definiujemy zmienną x i przypisujemy jej wartość
Serial.print(x);				// wyświetl wartość na monitorze
Serial.println( "cm" );			// wyświetl teks na monitorze
lcd.print("Dystans ");			//  wyświetl na LCD napis
lcd.print(x);				//  wyświetl na LCD wartość x
lcd.print( "cm" );			// wyświetl na LCD napis
if(x<10)				// wywołanie funkcji warunkowej sprawdzającej czy zmienna
 {					// jest mniejsza od 10
    digitalWrite(dioda1,HIGH);		// ustaw stan wysoki – świecenie diody
    digitalWrite(dioda2,LOW);		//ustaw stan niski – dioda nie świeci
    digitalWrite(dioda3,LOW);		//ustaw stan niski – dioda nie świeci
  }
if(x>10 && x<20)			// wywołanie funkcji warunkowej sprawdzającej czy zmienna
 {					// znajduje się w zdefiniowanym przedziale
    digitalWrite(dioda1,LOW);		//ustaw stan niski – dioda nie świeci
    digitalWrite(dioda2,HIGH);		// ustaw stan wysoki – świecenie diody
    digitalWrite(dioda3,LOW);		//ustaw stan niski – dioda nie świeci
  }
  if(x>20)				// wywołanie funkcji warunkowej sprawdzającej czy zmienna
 {					// jest większa od 20
    digitalWrite(dioda1,LOW);		//ustaw stan niski – dioda nie świeci
    digitalWrite(dioda2,LOW);		//ustaw stan niski – dioda nie świeci
    digitalWrite(dioda3,HIGH);		//ustaw stan wysoki – dioda świeci
  }
delay(1000);				//czekaj 1000ms
 lcd.clear();				//czyszczenie LCD
}
