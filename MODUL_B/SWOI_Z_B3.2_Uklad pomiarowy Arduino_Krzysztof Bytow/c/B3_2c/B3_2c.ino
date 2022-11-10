int diody[] = {-1,3,5,6};			// tablica zawierająca numery wyj. cyfrowych
int size = 4;				// wielkość tablicy
int j = 0;					// tworzymy zmienną „j” i przypisujemy jej wartość 0

void setup()				// część przygotowawcza

{
    for (int i=1; i< size; i++) 		// pętla for
 {
    pinMode(diody[i], OUTPUT);		//ustawienie pinów jako wyjścia 
  }
}

void loop()					// główna pętla programu

{
j = analogRead(0);    //przypisanie do zmiennej „j” wartości odczytanej z wejścia analogowego 0
j = j/128;                   		           //dzielimy otrzymaną wartość przez 128
for (int i=1;i<size;i++) 
{
    if (i <= j )  		 //wejście w przypadku poprawności wyrażenia j większe równe i
	{
      digitalWrite(diody[i], HIGH); 	// ustaw stan wysoki na diodach
     } 
else					//wykonanie kodu w przypadku niespełnienia warunku
   {
      digitalWrite(diody[i], LOW); 	//ustaw stan niski na diodach
    }
  }
  delay(200);				//czekaj 200 milisekund = 2 sekundy
}

