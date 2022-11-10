int d1=5;				// przyznanie etykiet dla pinu
int d2=6;				// przyznanie etykiet dla pinu
int d3=7;				// przyznanie etykiet dla pinu

void setup()			// początkowa konfiguracja – część przygotowująca układ do
{					// działania
pinMode(d1,OUTPUT);		// ustawienie pinu d1 jako wyjście
digitalWrite(d1,LOW);		// ustawienie na nim stanu niskiego
pinMode(d2,OUTPUT);		// analogicznie jak wyżej
digitalWrite(d2,LOW);		// analogicznie jak wyżej
pinMode(d3,OUTPUT);
digitalWrite(d3,LOW);
}

void loop()			// główna pętla
{
  if (analogRead(0) < 400)     // instrukcja warunkowa sprawdzająca odczyt z wej. analogowego
  { 
    digitalWrite(d1,HIGH);	// ustawienie stanu wysokiego dla d1 – dioda świeci
    digitalWrite(d2,LOW);	// ustawienie stanu niskiego dla d2 – dioda nie świeci
    digitalWrite(d3,LOW);	// ustawienie stanu niskiego dla d3 – dioda nie świeci
  }
  else if (analogRead(0) >= 400 and analogRead(0) <= 700) // zakres wartości jeśli spełniony
  {								         // to wykona kod
    digitalWrite(d1,LOW);	// ustawienie stanu niskiego dla d1 – dioda nie świeci
    digitalWrite(d2,HIGH);	// ustawienie stanu wysokiego dla d2 – dioda świeci
    digitalWrite(d3,LOW);	//  ustawienie stanu niskiego dla d3 – dioda nie świeci
  }
  else				// wykonanie gdy powyższe warunki nie są spełnione
  {
   digitalWrite(d1,LOW);	// ustawienie stanu niskiego dla d1 – dioda nie świeci
   digitalWrite(d2,LOW);	// ustawienie stanu niskiego dla d2 – dioda nie świeci
   digitalWrite(d3,HIGH);	// ustawienie stanu wysokiego dla d3 – dioda świeci
  }
}

