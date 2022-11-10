#include <stdio.h>

int main(void)
{
    int zmienna=42, zmienna2=24;
    int *wskaznik;

    wskaznik = &zmienna;

    printf("Zmienna ma wartosc: %d\n", zmienna);
    printf("Zmienna znajduje się pod adresem: %p\n\n", &zmienna);

    printf("Wskaznik wskazuje na adres: %p\n", wskaznik);
    printf("Zmienna pod tym adresem ma wartosc: %d\n", *wskaznik);
    printf("Wskaznik znajduje się pod adresem: %p\n\n\n", &wskaznik);


    *wskaznik = 5;

    printf("Zmienna ma wartosc: %d\n", zmienna);
    printf("Zmienna znajduje się pod adresem: %p\n\n", &zmienna);

    printf("Wskaznik wskazuje na adres: %p\n", wskaznik);
    printf("Zmienna pod tym adresem ma wartosc: %d\n", *wskaznik);
    printf("Wskaznik znajduje się pod adresem: %p\n\n\n", &wskaznik);


    wskaznik = &zmienna2;

    printf("Zmienna ma wartosc: %d\n", zmienna2);
    printf("Zmienna znajduje się pod adresem: %p\n\n", &zmienna2);

    printf("Wskaznik wskazuje na adres: %p\n", wskaznik);
    printf("Zmienna pod tym adresem ma wartosc: %d\n", *wskaznik);
    printf("Wskaznik znajduje się pod adresem: %p\n\n\n", &wskaznik);

    return 0;
}
