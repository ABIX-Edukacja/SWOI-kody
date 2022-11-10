#include <stdio.h>

union liczba
{
    int calkowita;
    float zmiennoprzecinkowa;
};

int main(void)
{
    union liczba zmienna;
    char wybierz;

    printf("Jakiego typu zmienna chcesz wykorzystac? (c)alkowita / (z)miennoprzecinkowa: ");
    scanf("%c", &wybierz);

    printf("Podaj liczbe: ");
    if(wybierz == 'c')
    {
        scanf("%d", &zmienna.calkowita);
    }
    else
    {
        scanf("%f", &zmienna.zmiennoprzecinkowa);
    }

    return 0;
}
