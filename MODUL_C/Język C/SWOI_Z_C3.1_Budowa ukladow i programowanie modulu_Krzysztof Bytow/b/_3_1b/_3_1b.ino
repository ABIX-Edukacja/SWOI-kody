int led = 6;   			// przyznanie etykiety dla numeru pinu
int s1=8;				// przyznanie etykiety dla numeru pinu

void pulse()			// miganie diody	
{
for(int i=0; i<=3; i++)		// w pętli następuje zmiana wartości „i” od 0 do 3
{
digitalWrite(led, LOW);		// ustawienie stanu niskiego dioda nie świeci
delay(150);			// czekaj wyznaczony czas 
digitalWrite(led, HIGH);		// ustawienie stanu wysokiego dioda świeci
delay(150);			 // czekaj wyznaczony czas 
}
delay(200);			 // czekaj wyznaczony czas 
}

void setup()			// początkowa konfiguracja – część przygotowująca układ
{ 					// do działania
pinMode(led,OUTPUT);		// ustawienie pinu jako wejście
digitalWrite(led,LOW);		// ustawienie stanu niskiego
pinMode(s1,INPUT);		// ustawienie pinu jako wejście
digitalWrite(s1,HIGH);		// ustawienie stanu wysokiego (pullup)
} 

void loop()				// główna pętla
{ 
  for(int i=0; i<=255; i+=5)	// w pętli następuje zmiana wartości „i” od 0 do 255
  { 
    analogWrite(led, i); 		// PWM – modulacja szerokości impulsu, (pin, wartość od 0 					// do 255)
    if (digitalRead(s1) == LOW) 	// warunek sprawdza czy wduszono button
 {
   pulse();				// wywołanie funkcji pulse
 }   
    delay(50);                           // czekaj wyznaczony czas 
  } 

  for(int i=255; i>=0; i-=5)	// w pętli następuje zmiana wartości „i” od 255 do 0
  { 
  analogWrite(led, i);		// PWM – modulacja szerokości impulsu, (pin, wartość)
  if (digitalRead(s1) == LOW) 	// warunek sprawdza czy wduszono button
 {
   pulse();				// wywołanie funkcji pulse
 } 
    delay(50);                        // czekaj wyznaczony czas  
  } 
}
