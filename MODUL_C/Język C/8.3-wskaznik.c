#include <stdio.h>

struct cyfra
{
  int x;
};

int main(void)
{
  struct cyfra zmienna;
  struct cyfra *wskaznik;

  zmienna.x = 42;
  wskaznik = &zmienna;

  printf("Wartosc x: %d\n", zmienna.x);
  wskaznik->x = 56;
  printf("Wartosc x: %d\n", wskaznik->x);

  return 0;
}
