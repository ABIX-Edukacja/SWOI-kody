a = int(input('Podaj długość pierwszego boku: '))
b = int(input('Podaj długość drugiego boku: '))
c = int(input('Podaj długość trzeciego boku: '))

if a + b >= c:
  if a + c >= b:
    if b + c >= a:
      print("Z takich odcinkow da sie zbudowac trojkat");
    else:
      print("Suma odcinkow b i c jest krotsza niz odcinek a");
  else:
    print("Suma odcinkow a i c jest krotsza niz odcinek b");
else:
  print("Suma odcinkow a i b jest krotsza niz odcinek c");
