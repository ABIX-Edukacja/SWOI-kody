lista = []
for i in range(5):
  a = int(input('Podaj liczbę: '))
  lista.append(a)

suma = 0
for element in lista:
  print(element)
  suma += element

print('Średnia: {0}'.format(suma / len(lista)))
