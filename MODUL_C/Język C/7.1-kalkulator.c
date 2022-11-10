#include <stdio.h>

int dodawanie(int x, int y);
int odejmowanie(int x, int y);
int mnozenie(int x, int y);
int dzielenie(int x, int y);

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
                wynik = dodawanie(cyfra1, cyfra2);
                break;
            case 2:
                wynik = odejmowanie(cyfra1, cyfra2);
                break;
            case 3:
                wynik = mnozenie(cyfra1, cyfra2);
                break;
            case 4:
                if(cyfra2 == 0)
                {
                    printf("Nie wolno dzielic przez zero\n");
                    return 1;
                }
                wynik = dzielenie(cyfra1, cyfra2);
                break;
            default:
                printf("Wybrales nieistniejaca opcje\n");
                return 1;
        }

        printf("Wynik wynosi: %d\n", wynik);

        do
        {
            printf("\nCzy chcesz wykonac kolejne obliczenie? (t/n): ");
            getchar();
            scanf("%c", &kontynuj);
            if(kontynuj == 'n')
            {
                wyjscie = 1;
            }
            else if(kontynuj != 't')
            {
                printf("Podales bledna litere!\n");
            }
        } while((kontynuj != 't') && (kontynuj != 'n'));
    }

    return 0;
}

int dodawanie(int x, int y)
{
    int suma;

    suma = x + y;
    return suma;
}

int odejmowanie(int x, int y)
{
    int suma;

    suma = x - y;
    return suma;
}

int mnozenie(int x, int y)
{
    int suma;

    suma = x * y;
    return suma;
}

int dzielenie(int x, int y)
{
    int suma;

    suma = x / y;
    return suma;
}
