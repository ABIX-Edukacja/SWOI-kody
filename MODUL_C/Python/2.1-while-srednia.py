suma = 0
licznik = 0
while True:
  liczba = int(input('Podaj liczbę (0 aby zakończyć): '))
  if liczba == 0:
    break
  suma += liczba
  licznik += 1

print('Średnia wynosi: {0}'.format(suma/licznik))
