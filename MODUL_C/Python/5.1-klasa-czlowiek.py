class Czlowiek:
  def __init__(self, imie, nazwisko, plec, wiek, wzrost):
    self.imie = imie
    self.nazwisko = nazwisko
    self.plec = plec
    self.wiek = wiek
    self.wzrost = wzrost
  
  def __str__(self):
    opis = 'Imię: ' + self.imie + '\nNazwisko: ' + self.nazwisko + '\nPłeć: ' + self.plec + '\nWiek: ' + str(self.wiek) + '\nWzrost: ' + str(self.wzrost)
    return opis
  
  def postarz(self, ile = 1):
    self.wiek += ile

  def urosnij(self, ile = 1):
    self.wzrost += ile

  def zmien_nazwisko(self, nowe_nazwisko):
    self.nazwisko = nowe_nazwisko

pawel = Czlowiek('Paweł', 'Kowalski', 'M', 16, 170)
kasia = Czlowiek('Kasia', 'Kowalska', 'M', 13, 152)

print(pawel, '\n', kasia)

pawel.postarz()
print(pawel)

pawel.urosnij(3)
print(pawel)

kasia.zmien_nazwisko('Malinowska')
print(kasia)
