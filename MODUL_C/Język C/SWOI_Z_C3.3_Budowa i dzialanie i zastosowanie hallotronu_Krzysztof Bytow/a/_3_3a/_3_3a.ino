int dioda1 = 4; 			//przyznanie etykiety dla numeru pinu
int dioda2 = 5; 			//przyznanie etykiety dla numeru pinu
int dioda3 = 6; 			//przyznanie etykiety dla numeru pinu
int czujnik = 7; 			//przyznanie etykiety dla numeru pinu
int stan = 0; 				// przypisanie wartości

void setup()				// początkowa konfiguracja – część przygotowująca układ 
{					// do działania
  pinMode(czujnik, INPUT);		// ustawienie pinu jako wejście
  pinMode(dioda1, OUTPUT);	// ustawienie pinu jako wyjście
  pinMode(dioda2, OUTPUT);	// ustawienie pinu jako wyjście
  pinMode(dioda3, OUTPUT);	// ustawienie pinu jako wyjście
  digitalWrite(czujnik, HIGH);	// ustawienie stanu wysokiego
}

void loop()				// główna pętla
{
  stan = digitalRead(czujnik);	// przypisanie wartości odczytanej z pinu 4 (czujnik)

  if (stan == HIGH)		// wywołanie funkcji warunkowej sprawdzającej czy zmienna
{					// stan ma wartość HIGH (stan wysoki)
    digitalWrite(dioda1, LOW);	// ustaw stan niski – dioda nie świeci
    digitalWrite(dioda2, LOW);	// ustaw stan niski – dioda nie świeci
    digitalWrite(dioda3, LOW);	// ustaw stan niski – dioda nie świeci
  }
  else					// w przypadku niespełnienia powyższego warunku 
{					// wykonany zostanie poniższy kod
    digitalWrite(dioda1, HIGH);	// ustaw stan wysoki – świecenie diody
    delay(500);			//czekaj 500ms
    digitalWrite(dioda1, LOW);	// ustaw stan niski – dioda nie świeci
    delay(100);			//czekaj 100ms
    digitalWrite(dioda2, HIGH);	// ustaw stan wysoki – świecenie diody
    delay(500);			//czekaj 500ms
    digitalWrite(dioda2, LOW);	// ustaw stan niski – dioda nie świeci
    delay(100);			//czekaj 100ms
     digitalWrite(dioda3, HIGH);	// ustaw stan wysoki – świecenie diody
    delay(500);			//czekaj 500ms
    digitalWrite(dioda3, LOW);	// ustaw stan niski – dioda nie świeci
    delay(100);			//czekaj 100ms
  }
}
