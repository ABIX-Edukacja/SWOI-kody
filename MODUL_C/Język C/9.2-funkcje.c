#include <stdio.h>

void dodawanie(int x, int y, int *suma);

int main(void)
{
    int zmienna1, zmienna2, wynik;

    printf("Podaj pierwsza zmienna:");
    scanf("%d", &zmienna1);

    printf("Podaj druga zmienna:");
    scanf("%d", &zmienna2);

    dodawanie(zmienna1, zmienna2, &wynik);

    printf("Wynik wynosi: %d\n", wynik);

    return 0;
}

void dodawanie(int x, int y, int *suma)
{
    *suma = x + y;
}
