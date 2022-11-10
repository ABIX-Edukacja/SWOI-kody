int dioda1 = 6;			// przyznanie etykiety dla numeru pinu
int dioda2 = 5;			// przyznanie etykiety dla numeru pinu
int dioda3 = 4;			// przyznanie etykiety dla numeru pinu
int buton = 7;			// przyznanie etykiety dla numeru pinu

void setup()				// początkowa konfiguracja – część przygotowująca 
{					// układ do działania
  pinMode(dioda1, OUTPUT);	// ustawienie pinu jako wyjście
  digitalWrite(dioda1, HIGH);	// ustawienie stanu wysokiego
  pinMode(dioda2, OUTPUT);	// ustawienie pinu jako wyjście
  digitalWrite(dioda2, LOW);	// ustawienie stanu niskiego
  pinMode(dioda3, OUTPUT);	// ustawienie pinu jako wyjście
  digitalWrite(dioda3, LOW);	// ustawienie stanu niskiego
  pinMode(buton, INPUT);		// ustawienie pinu jako wejście
  digitalWrite(buton, HIGH);	// ustawienie stanu wysokiego (pullup)
}

void loop()				// główna pętla
{
if(digitalRead(buton) == LOW)	 //  warunek sprawdza czy wduszono button
{					// wduszenie buttona powoduje zmianę stanu z wysokiego na niski
digitalWrite(dioda1, LOW); 	// ustawienie stanu niskiego
digitalWrite(dioda2, HIGH);	// ustawienie stanu wysokiego
digitalWrite(dioda3, LOW);		// ustawienie stanu niskiego
}
if(digitalRead(buton) == LOW) 	//  warunek sprawdza czy wduszono button
{					// wduszenie buttona powoduje zmianę stanu z wysokiego na niski
digitalWrite(dioda1, LOW);		// ustawienie stanu niskiego
digitalWrite(dioda2, LOW);		// ustawienie stanu niskiego
digitalWrite(dioda3, HIGH);	// ustawienie stanu wysokiego
}
if(digitalRead(buton) == LOW)	 // warunek sprawdza czy wduszono button
{					// wduszenie buttona powoduje zmianę stanu z wysokiego na niski
digitalWrite(dioda1, HIGH);	// ustawienie stanu wysokiego
digitalWrite(dioda2, LOW);		// ustawienie stanu niskiego
digitalWrite(dioda3, LOW);		// ustawienie stanu niskiego
}
}
