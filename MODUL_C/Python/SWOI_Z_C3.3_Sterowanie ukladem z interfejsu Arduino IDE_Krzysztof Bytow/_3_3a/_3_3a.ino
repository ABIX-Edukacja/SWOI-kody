int x,i=120;				// tworzymy zmienną x

void pwm_off()
{
analogWrite(9,0);
analogWrite(10,0);
analogWrite(11,0);
}

void losuj()
{
int y=x;
x = random(9,12);
while (x==y)
{
x = random(9,12);
}
}

void setup()			
{
for(int i=9;i<12;i++)		// w pętli ustawiamy porty Arduino jako wyjścia i ustalamy
{					// stan niski
pinMode(i,OUTPUT);		// ustaw jako wyjście
digitalWrite(i,LOW);		// ustaw stan niski
}
for(int i=5;i<=7;i++)		// w pętli ustawiamy porty Arduino jako wejścia i ustalamy
{					// stan wysoki
pinMode(i,INPUT);		// ustaw jako wejście
digitalWrite(i,HIGH);		// ustaw stan wysoki
}
Serial.begin(9600);		// ustawienie prędkości komunikacji
losuj();
analogWrite(x,i);  		// PWM – modulacja szerokości impulsu, (pin, wartość od 0
}	

	// do 255)
void loop()			// główna pętla
{
 if(digitalRead(6)==LOW)	// warunek sprawdza czy wduszono button
   {
    losuj();
    Serial.println(x);
    pwm_off();
    analogWrite(x,i); 		// PWM – modulacja szerokości impulsu, (pin, wartość)
    delay(250);					// czekaj wyznaczony czas 
    }
  if(digitalRead(7)==LOW)	// warunek sprawdza czy wduszono button
  {
  i =i+15;
  i=constrain(i,0,255);  		// ograniczenie liczby w przedziale
  analogWrite(x,i);		// PWM – modulacja szerokości impulsu, (pin, wartość)
  delay(250);					// czekaj wyznaczony czas 
  }
  if(digitalRead(5)==LOW)	// warunek sprawdza czy wduszono button
  {
  i =i-15;
  i=constrain(i,0,255);  		// ograniczenie liczby w przedziale
  analogWrite(x,i);		// PWM – modulacja szerokości impulsu, (pin, wartość)
  delay(250);  					// czekaj wyznaczony czas 
   }
}
