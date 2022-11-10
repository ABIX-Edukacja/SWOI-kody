int dioda = 10;			// przyznanie etykiety dla numeru pinu
int buton = 2;    			// przyznanie etykiety dla numeru pinu
void setup()    			// początkowa konfiguracja – część przygotowująca układ do
{             				// działania
pinMode(dioda, OUTPUT);		// ustawienie pinu jako wyjście
digitalWrite(dioda, LOW);		// ustawienie stanu niskiego
pinMode(buton, INPUT); 		// ustawienie pinu jako wejście
digitalWrite(buton, HIGH); 	// ustawienie stanu wysokiego (pullup)
};
void loop()           			// główna pętla
{
if(digitalRead(buton) == LOW && digitalRead(dioda)==LOW) 	
				// warunek sprawdza czy wduszono button i czy dioda nie świeci
{				 // wduszenie buttona powoduje zmianę stanu z niskiego na wysoki
digitalWrite(dioda, HIGH); 				// ustawienie stanu wysoki dioda świeci
delay(200);						// czekaj 200ms
}
if(digitalRead(buton) == LOW && digitalRead(dioda)==HIGH) 
				// warunek sprawdza czy wduszono button i czy dioda świeci
{                       
digitalWrite(dioda, LOW); 					// ustawienie stanu niskiego
delay(200);						// czekaj 200ms
}
}
