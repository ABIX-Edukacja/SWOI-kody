#include <stdio.h>

int main(void)
{
    int zmienna, cyfra1, cyfra2, wynik, wyjscie=0;
    char kontynuj;

    while(wyjscie == 0)
    {
        printf("Jaką operację chcesz wykonać?\n1) dodawanie\n2) odejmowanie\n3) mnożenie\n4) dzielenie\n");
        scanf("%d", &zmienna);

        printf("Podaj pierwszą cyfrę do operacji: ");
        scanf("%d", &cyfra1);
        printf("Podaj drugą cyfrę do operacji: ");
        scanf("%d", &cyfra2);

        switch(zmienna)
        {
            case 1:
                wynik = cyfra1 + cyfra2;
                break;
            case 2:
                wynik = cyfra1 - cyfra2;
                break;
            case 3:
                wynik = cyfra1 * cyfra2;
                break;
            case 4:
                if(cyfra2 == 0)
                {
                    printf("Nie wolno dzielic przez zero\n");
                    return 1;
                }
                wynik = cyfra1 / cyfra2;
                break;
            default:
                printf("Wybrales nieistniejaca opcje\n");
                return 1;
        }

        printf("Wynik wynosi: %d\n", wynik);

        while(1)
        {
            printf("\nCzy chcesz wykonac kolejne obliczenie? (t/n): ");
            getchar();
            scanf("%c", &kontynuj);
            if(kontynuj == 't')
            {
                break;
            }
            else if(kontynuj == 'n')
            {
                wyjscie = 1;
                break;
            }
            else
            {
                printf("Podales bledna litere!\n");
            }
        }
    }

    return 0;
}
