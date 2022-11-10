#include <stdio.h>

int main(void)
{
    int zmienna, cyfra1, cyfra2, wynik;

    printf("Jaką operację chcesz wykonać?\n1) dodawanie\n2) odejmowanie\n3) mnożenie\n4) dzielenie\n");
    scanf("%d", &zmienna);

    printf("Podaj pierwszą cyfrę do operacji: ");
    scanf("%d", &cyfra1);
    printf("Podaj drugą cyfrę do operacji: ");
    scanf("%d", &cyfra2);

    if(zmienna == 1)
    {
        wynik = cyfra1 + cyfra2;
    }
    else if(zmienna == 2)
    {
        wynik = cyfra1 - cyfra2;
    }
    else if(zmienna == 3)
    {
        wynik = cyfra1 * cyfra2;
    }
    else if(zmienna == 4)
    {
        wynik = cyfra1 / cyfra2;
    }
    else
    {
        printf("Wybrales nieistniejaca opcje\n");
        return 1;
    }

    printf("Wynik wynosi: %d\n", wynik);

    return 0;
}
