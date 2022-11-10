unit gra;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, FileUtil, LResources, Forms, Controls, Graphics, Dialogs,
  ExtCtrls, StdCtrls;

type

  { TOkno }

  TOkno = class(TForm)
    Link: TLabel;
    Start: TButton;
    Opis: TLabel;
    Obrazki: TImageList;
    Info: TLabel;
    procedure StartClick(Sender: TObject);
    procedure FormCreate(Sender: TObject);
    procedure Rzad1Click(Sender: TObject);
    procedure Rzad2Click(Sender: TObject);
    procedure Rzad3Click(Sender: TObject);
    procedure Rzad1Action(kulka: Integer);
    procedure Rzad2Action(kulka: Integer);
    procedure Rzad3Action(kulka: Integer);
    procedure SprawdzKoniec();
    procedure PCMove();
  private
    { private declarations }
    ile1, ile2, ile3: Integer;
    tura: Integer;
    koniec: Boolean;
    Grzyb1: array[1..10] of TImage;
    Grzyb2: array[1..10] of TImage;
    Grzyb3: array[1..10] of TImage;
  public
    { public declarations }
  end; 

var
  Okno: TOkno;
  i: Integer;

implementation

{ TOkno }

procedure TOkno.FormCreate(Sender: TObject); { procedura wywoływana tylko raz podczas tworzenia okna }
begin

  for i:= 1 to 10 do { stwórz wszystkie elementy tablicy }
  begin
    Grzyb1[i]:= TImage.Create(self); { stwórz element }
    Grzyb1[i].Parent:= self; { przypisz go do okna }
    Grzyb1[i].Visible:= False; { ukryj go }
    Obrazki.GetBitmap(0, Grzyb1[i].Picture.Bitmap); { przypisz mu obrazek }
    Grzyb1[i].Top:= 16; { określ jego położenie od górnej krawędzi ekranu }
    Grzyb1[i].Left:= (64*i)-48; { określ jego położenie od lewej krawędzi ekranu }
    Grzyb1[i].Tag:= i; { przypisz mu numer porządkowy }
    Grzyb1[i].OnClick:= @Rzad1Click; { określ która procedura ma być wywoływana w momencie kliknięcia na obiekt }
  end;

  for i:= 1 to 10 do { drugi rząd - wszystko tak jak wyżej }
  begin
    Grzyb2[i]:= TImage.Create(self);
    Grzyb2[i].Parent:= self;
    Grzyb2[i].Visible:= False;
    Obrazki.GetBitmap(1, Grzyb2[i].Picture.Bitmap);
    Grzyb2[i].Top:= 80;
    Grzyb2[i].Left:= (64*i)-48;
    Grzyb2[i].Tag:= i;
    Grzyb2[i].OnClick:= @Rzad2Click;
  end;

  for i:= 1 to 10 do { i trzeci rząd }
  begin
    Grzyb3[i]:= TImage.Create(self);
    Grzyb3[i].Parent:= self;
    Grzyb3[i].Visible:= False;
    Obrazki.GetBitmap(2, Grzyb3[i].Picture.Bitmap);
    Grzyb3[i].Top:= 144;
    Grzyb3[i].Left:= (64*i)-48;
    Grzyb3[i].Tag:= i;
    Grzyb3[i].OnClick:= @Rzad3Click;
  end;
  Grzyb1[1].Visible:=True;
  Grzyb2[1].Visible:=True;
  Grzyb3[1].Visible:=True;
end;

procedure TOkno.StartClick(Sender: TObject); { funkcja obsługująca kliknięcie guzika START }
begin
  Start.Visible:= False; { ukryj przycisk }
  Link.Visible:= False; { ukryj adres autora ikon }
  Opis.Visible:= False; { ukryj opis gry }
  Info.Visible:= False; { ukryj Info o wygranej lub przegranej }
  koniec:= False; { ustaw zmienną oznaczającą koniec gry na Fałsz }
  tura:= 1; { ustaw licznik tur na zero }

  Randomize; { ustaw źródło generatora liczb losowych }
  ile1:= Random(10)+1; { wylosuj ilość kulek w 1 rzędzie }
  for i:= 1 to ile1 do { pętla przebiega przez elementy od pierwszego do wylosowanego }
    Grzyb1[i].Visible:= True; { i ustawia aby były widoczne }

  ile2:= Random(10)+1; { to samo dla drugiego rzędu }
  for i:= 1 to ile2 do
    Grzyb2[i].Visible:= True;

  ile3:= Random(10)+1; { i dla trzeciego }
  for i:= 1 to ile3 do
    Grzyb3[i].Visible:= True;
end;

procedure TOkno.Rzad1Click(Sender: TObject); { procedura obsługująca kliknięcie w element z pierwszego rzędu }
begin
  { Sender jest ogólną reprezentacją obiektu który został kliknięty
    przekształcamy go na konkretny obiekt w tym przypadku typu TImage
    i pobieramy z niego wartość atrybutu Tag którą od razu przekazujemy do procedury Rzad1Action }
  Rzad1Action((Sender as TImage).Tag);
  { sprawdź czy zmienna koniec została ustawiona na Fałsz,
    jeśli tak to znaczy że gra się nie skończyła i należy wykonać ruch komputera }
  if koniec = False then PCMove();
end;

procedure TOkno.Rzad2Click(Sender: TObject); { jak wyżej tylko dla drugiego rzędu }
begin
  Rzad2Action((Sender as TImage).Tag);
  if koniec = False then PCMove();
end;

procedure TOkno.Rzad3Click(Sender: TObject); { i dla trzeciego }
begin
  Rzad3Action((Sender as TImage).Tag);
  if koniec = False then PCMove();
end;

procedure TOkno.Rzad1Action(kulka: Integer); { procedura obsługująca zmiany stanów rzędu 1 }
begin
  tura:= tura+1; { zwiększ licznik tur }
  for i:= kulka to ile1 do { od grzyba klikniętego aż do ostatniej }
    Grzyb1[i].Visible:= False; { ukryj grzyba }
  ile1:= kulka-1; { ustaw nową wartość pozostałych kulek }
  SprawdzKoniec; { sprawdź czy nastąpił koniec gry }
end;

procedure TOkno.Rzad2Action(kulka: Integer); { to samo dla rzędu drugiego }
begin
  tura:= tura+1;
  for i:= kulka to ile2 do
    Grzyb2[i].Visible:= False;
  ile2:= kulka-1;
  SprawdzKoniec;
end;

procedure TOkno.Rzad3Action(kulka: Integer); { i rzędu trzeciego }
begin
  tura:= tura+1;
  for i:= kulka to ile3 do
    Grzyb3[i].Visible:= False;
  ile3:= kulka-1;
  SprawdzKoniec;
end;

procedure TOkno.SprawdzKoniec(); { procedura sprawdzająca czy wszystkie grzyby zostały "zabrane" }
begin
  if ile1+ile2+ile3 < 2 then { sprawdź czy nie pozostały żadne grzyby }
  begin
    if (tura mod 2) = 1 then { jeśli była tura gracza }
      Info.Caption:= 'Przegrana' { wyświetl informację o przegranej }
    else if ile1+ile2+ile3 = 1 then { jeśli była tura komputera }
      Info.Caption:= 'Wygrana' { o wygranej }
    else
      Info.Caption:= 'Przegrana';
    koniec:= True; { ustaw zmienną oznaczającą koniec gry }
    Info.Visible:= True; { pokaż Info }
    Start.Visible:= True; { pokaż przycisk START }
  end;
end;

procedure TOkno.PCMove(); { procedura realizująca ruch komputera, identyczna jak w implementacji w VisualBasic'u }
begin
  if (ile1=ile2) and (ile1<2) and (ile3>1) then
  begin
   Rzad3Action(2);
   Exit;
  end
  else if (ile1=ile3) and (ile1<2) and (ile2>1) then
  begin
    Rzad2Action(2);
    Exit;
  end
  else if (ile2=ile3) and (ile2<2) and (ile1>1) then
  begin
    Rzad1Action(2);
    Exit();
  end;

  If (ile1+ile2)=1 then
  begin
    Rzad3Action(1);
    Exit();
  end
  else if (ile1+ile3)=1 then
  begin
    Rzad2Action(1);
    Exit();
  end
  else if (ile2+ile3)=1 then
  begin
    Rzad1Action(1);
    Exit();
  end;

  for i:= 1 to 10 do
  begin
    if (ile1>=i) and (((ile1-i) xor ile2 xor ile3) = 0) then
    begin
      Rzad1Action(ile1 - i + 1);
      Exit();
    end
    else if (ile2>=i) and ((ile1 xor (ile2-i) xor ile3) = 0) then
    begin
      Rzad2Action(ile2 - i + 1);
      Exit();
    end
    else if (ile3>=i) and ((ile1 xor ile2 xor (ile3-i)) = 0) then
    begin
      Rzad3Action(ile3 - i + 1);
      Exit();
    end;
  end;

  if (ile1>=ile2) and (ile1>=ile3) and ((Random(10)/10)>0.5) then
    Rzad1Action(Random(ile1) + 1)
  else if (ile2>=ile1) and (ile2>=ile3) then
    Rzad2Action(Random(ile2) + 1)
  else
    Rzad3Action(ile3);
end;

initialization
  {$I gra.lrs}

end.

