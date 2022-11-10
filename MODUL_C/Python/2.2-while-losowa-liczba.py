import random

liczba = random.randint(0, 5)
print(liczba)
while int(input('Zgadnij liczbe: ')) != liczba:
  print('Zgaduj dalej')
print('Brawo!')
