a = int(input('Podaj pierwszą liczbę: '))
b = int(input('Podaj drugą liczbę: '))
c = int(input('Podaj trzecią liczbę: '))

if a > b:
  if a > c:
    if b > c:
      print("Cyfry w kolejnosci to a, b, c: {0}, {1}, {2}".format(a, b, c))
    else:
      print("Cyfry w kolejnosci to a, c, b: {0}, {1}, {2}".format(a, c, b))
  else:
    print("Cyfry w kolejnosci to c, a, b: {0}, {1}, {2}".format(c, a, b))
else:
  if b > c:
    if a > c:
      print("Cyfry w kolejnosci to b, a, c: {0}, {1}, {2}".format(b, a, c))
    else:
      print("Cyfry w kolejnosci to b, c, a: {0}, {1}, {2}".format(b, c, a))
  else:
    print("Cyfry w kolejnosci to c, b, a: {0}, {1}, {2}".format(c, b, a))
