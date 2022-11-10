import random

def funkcja(lista):
  maximum = 0
  for i in lista:
    if i > maximum:
      maximum = i
  return maximum

lista = []
for i in range(10):
  lista.append(random.randint(0, 100))

najwieksza = funkcja(lista)
print('Największa liczba z listy to: {0}'.format(najwieksza))
