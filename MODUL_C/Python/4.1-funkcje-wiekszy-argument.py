def funkcja(a, b):
  if a > b:
    return a
  else:
    return b

liczba1 = int(input('Podaj pierwszą liczbę: '))
liczba2 = int(input('Podaj drugą liczbę: '))
wieksza = funkcja(liczba1, liczba2)
print('Większe jest {0}'.format(wieksza))
