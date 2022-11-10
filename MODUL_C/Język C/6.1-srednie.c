#include <stdio.h>

int main(void)
{
    int licznik, liczby[5], wagi[5];
    int srednia, suma_wag;

    for(licznik=0; licznik<5; licznik++)
    {
        printf("Podaj %d liczbe: ", licznik);
        scanf("%d", &liczby[licznik]);
    }

    for(licznik=0; licznik<5; licznik++)
    {
        printf("Podaj wage dla %d liczby: ", licznik);
        scanf("%d", &wagi[licznik]);
    }

    for(licznik=srednia=0; licznik<5; licznik++)
    {
        srednia = srednia + liczby[licznik];
    }
    srednia = srednia / 5;
    printf("Srednia arytmetyczna wynosi: %d\n", srednia);

    for(licznik=suma_wag=srednia=0; licznik<5; licznik++)
    {
        srednia = srednia + (liczby[licznik] * wagi[licznik]);
        suma_wag = suma_wag + wagi[licznik];
    }
    srednia = srednia / suma_wag;
    printf("Srednia wazona wynosi: %d\n", srednia);

    return 0;
}
