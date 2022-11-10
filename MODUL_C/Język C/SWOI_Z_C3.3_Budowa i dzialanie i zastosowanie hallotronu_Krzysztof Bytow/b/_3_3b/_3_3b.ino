int dioda1 = 3;				// przyznanie etykiety dla numeru pinu
int dioda2 = 5;				// przyznanie etykiety dla numeru pinu
int dioda3 = 6;				// przyznanie etykiety dla numeru pinu
int buzer = 8;				// przyznanie etykiety dla numeru pinu

void playTone(int tone, int duration) 	// część odpowiedzialna za granie buzzera 
{
  for (long i = 0; i < duration * 1000L; i += tone * 2)  // pętla for wykonywana do momentu
 {						// poprawności warunku
    digitalWrite(buzer, HIGH);		// ustaw stan wysoki – buzer gra
    delayMicroseconds(tone);		// oczekuj wartość „tone” wyrażoną w mikrosekundach
    digitalWrite(buzer, LOW);		// ustaw stan niski – cisza
    delayMicroseconds(tone);		// oczekuj wartość „tone” wyrażoną w mikrosekundach
  }
}

void setup()
{
  pinMode(dioda1, OUTPUT);		// ustawienie pinu jako wyjście
  digitalWrite(dioda1, LOW);		// ustawienie stanu niskiego – dioda nie świeci
  pinMode(dioda2, OUTPUT);		// ustawienie pinu jako wyjście
  digitalWrite(dioda2, LOW);		// ustawienie stanu niskiego – dioda nie świeci
  pinMode(dioda3, OUTPUT);		// ustawienie pinu jako wyjście
  digitalWrite(dioda3, LOW);		// ustawienie stanu niskiego – dioda nie świeci
  pinMode(buzer, OUTPUT);		// ustawienie pinu jako wyjście
  Serial.begin(9600);			// ustawienie prędkości transmisji
};

void loop()				// główna pętla
{
int x=random(500,2500);			//przypisanie zmiennej typu intiger wartości losowej z
						//przedziału (500,2500)
unsigned long int y=x/1000.0;		//przeliczenie na sekundy
Serial.print("Wylosowany czas: ");	//wyświetlenie tekstu
Serial.print(x);				//wyświetlenie wartości (x)
Serial.print(" milisekund = ");		//wyświetlenie tekstu
Serial.print(y);				//wyświetlenie wartości (y)
Serial.println(" sekundy");		//wyświetlenie tekstu
for (int i = 0; i < 4; i++)		//pętla for, wykonywana do momentu spełnienia warunku
{					//  przypisujemy „i” wartość 0, sprawdzamy czy jest mniejsza  
					// od (i<4); następnie zwiększamy o 1 (i++)
playTone(1915, 150);		// wywołanie playTone z wartościami (1915,150)
digitalWrite(dioda1, HIGH);		// ustaw stan wysoki – dioda świeci
delay(x);				// odczekaj „x” milisekund
playTone(1915, 150);		// wywołanie playTone z wartościami (1915,150)
digitalWrite(dioda1, LOW);		// ustaw stan niski – dioda gaśnie
digitalWrite(dioda2, HIGH);		// ustaw stan wysoki - dioda świeci
delay(x);				// odczekaj „x” milisekund
playTone(1915, 150);		// wywołanie playTone z wartościami (1915,150)
digitalWrite(dioda2, LOW);		// ustaw stan niski – dioda gaśnie
digitalWrite(dioda3, HIGH);		// ustaw stan wysoki - dioda świeci
delay(x);				// odczekaj „x” milisekund
digitalWrite(dioda3, LOW);		// ustaw stan niski – dioda gaśnie
}
};
