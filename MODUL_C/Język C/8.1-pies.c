#include <stdio.h>

struct pies
{
    char rasa[100];
    char imie[100];
    char masc[100];
    int wiek;
    char plec;
};

int main(void)
{
    struct pies piesek;

    printf("Podaj imie psa: ");
    scanf("%s", piesek.imie);
    printf("Podaj rase: ");
    scanf("%s", piesek.rasa);
    printf("Jakiej masci jest pies: ");
    scanf("%s", piesek.masc);
    printf("Ile lat ma pies: ");
    scanf("%d", &piesek.wiek);
    printf("Jakie plci jest pies - (p)ies lub (s)uczka: ");
    getchar();
    scanf("%c", &piesek.plec);

    if(piesek.plec == 'p')
    {
        printf("Pies ma na imie %s. Jest rasy %s, w kolorze %s i ma %d lat(a).\n", piesek.imie, piesek.rasa, piesek.masc, piesek.wiek);
    }
    else
    {
        printf("Suczka ma na imie %s. Jest rasy %s, w kolorze %s i ma %d lat(a).\n", piesek.imie, piesek.rasa, piesek.masc, piesek.wiek);
    }

    return 0;
}
