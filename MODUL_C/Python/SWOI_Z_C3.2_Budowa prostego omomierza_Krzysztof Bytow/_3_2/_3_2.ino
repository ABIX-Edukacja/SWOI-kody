float r1= 10000.0;    // wartosc rezystora ktorego znamy (w naszym przypadku 10 kOhm)

void setup()
{
  Serial.begin(9600);
}
 
void loop()
{
  float Uwyj = (5.0/1024.0) * float(analogRead(0));	//odczyt przekształcamy na napięcie
  float R=r1*((5.0/Uwyj)-1);			//wzór po odpowiednich przekształceniach
  Serial.print("Napiecie wyj: "); Serial.println(Uwyj); 	//wyświetlenie tekstu        
  Serial.print("Wartosc rezystora: "); Serial.println(R);	//wyświetlenie tekstu      
  delay(3000);
}
