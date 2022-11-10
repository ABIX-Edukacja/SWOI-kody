unit swiatelka; 

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, FileUtil, LResources, Forms, Controls, Graphics, Dialogs,
  StdCtrls, ExtCtrls;

type

  { TForm1 }

  TForm1 = class(TForm)
    // deklaracje obiektów znajdujących się na planszy
    Obrazki: TImageList;
    Start: TButton;
    Stop: TButton;
    // deklaracje procedur
    procedure FormCreate(Sender: TObject);
    procedure StartClick(Sender: TObject);
    procedure StopClick(Sender: TObject);
    procedure LampkaClick(Sender: TObject);
    procedure OdwrocLampki(rzad, kolumna: Integer);
  private
    // deklaracje zmiennych
    gramy: Boolean;
    Lampki: array[0..4, 0..4] of TImage;
    Zapalona: array[0..4, 0..4] of Boolean;
  public
    { public declarations }
  end; 

var
  Form1: TForm1;
  i, j: Integer;  // deklaracje zmiennych używanych jako iteratory

implementation

{ TForm1 }

// metoda wywoływana w momencie tworzenia okna
procedure TForm1.FormCreate(Sender: TObject);
begin
  gramy:= True;  // zmienna przechowująca informację czy gra się toczy

  // pętla tworząca kratki lampek na ekranie
  for i:=0 to 4 do  // przesuwanie się po rzędach tablicy
  begin
    for j:=0 to 4 do  // przesuwanie się po kolumnach tablicy
    begin
      Lampki[i,j]:= TImage.Create(self);  // stworzenie lampki
      Lampki[i,j].Parent:= self;  // przypisanie lampki do okna
      Lampki[i,j].Width:= 100;  // określeni szerokości lampki
      Lampki[i,j].Height:= 100;  // określenie wysokości lampki
      Obrazki.GetBitmap(0, Lampki[i,j].Picture.Bitmap);  // określenie obrazku lampki
      Lampki[i,j].Left:= (j+1)*5 + j*100;  // określenie położenia lampki od lelwej krawędzi okna
      Lampki[i,j].Top:= (i+1)*5 + i*100;  // określenie położenia lampki od góry okna
      Lampki[i,j].Tag:= i*5+j;  // przypisanie lampce numeru
      Lampki[i,j].OnClick:= @LampkaClick;  // przypisanie do lampki funkcji do obsłuhi kliknięć

      Zapalona[i,j]:= False;  // wypełnienie osobnej tablicy przechowującej informacje o stanie lampek
    end;
  end;

  // wzor na poczatek
  Zapalona[1,1]:=True;
  Zapalona[1,2]:=True;
  Zapalona[1,3]:=True;
  Zapalona[2,1]:=True;
  Zapalona[2,2]:=True;
  Zapalona[2,3]:=True;
  Zapalona[3,1]:=True;
  Zapalona[3,2]:=True;
  Zapalona[3,3]:=True;
  Obrazki.GetBitmap(1, Lampki[1,1].Picture.Bitmap);
  Obrazki.GetBitmap(1, Lampki[1,2].Picture.Bitmap);
  Obrazki.GetBitmap(1, Lampki[1,3].Picture.Bitmap);
  Obrazki.GetBitmap(1, Lampki[2,1].Picture.Bitmap);
  Obrazki.GetBitmap(1, Lampki[2,2].Picture.Bitmap);
  Obrazki.GetBitmap(1, Lampki[2,3].Picture.Bitmap);
  Obrazki.GetBitmap(1, Lampki[3,1].Picture.Bitmap);
  Obrazki.GetBitmap(1, Lampki[3,2].Picture.Bitmap);
  Obrazki.GetBitmap(1, Lampki[3,3].Picture.Bitmap);
end;

// procedura wywoływana w momencie kliknięcia guzika GRAJ
procedure TForm1.StartClick(Sender: TObject);
begin
  gramy:= True;  // start gry
end;

// procedura wywoływana w momencie kliknięcia guzika USTAWIAJ
procedure TForm1.StopClick(Sender: TObject);
begin
  gramy:= False;  // przerwanie gry i przejśćie do trybu ustawiania
end;

procedure TForm1.LampkaClick(Sender: TObject);
var
  rzad, kolumna: Integer;  // zmienne lokalne procedury
begin
  kolumna:= (Sender as TImage).Tag mod 5;
  rzad:= (Sender as TImage).Tag div 5;

  { jesli gramy }
  if gramy = True then
  begin
    OdwrocLampki(rzad, kolumna);
  end
  { jesli nie gramy }
  else
  begin
    { jesli lampka byla zapalona zgaś lampkę }
    if Zapalona[rzad, kolumna] = True then
    begin
      Zapalona[rzad, kolumna]:= False;
      Obrazki.GetBitmap(0, Lampki[rzad, kolumna].Picture.Bitmap);
    end
    { jesli lampka byla zgaszona zapal lampkę }
    else
    begin
      Zapalona[rzad, kolumna]:= True;
      Obrazki.GetBitmap(1, Lampki[rzad, kolumna].Picture.Bitmap);
    end;
  end;
end;

// funkcja obsługująca grę - zmienia stan lampki i jej sąsiadów
procedure TForm1.OdwrocLampki(rzad, kolumna: Integer);
begin
  //obsługa lampek sąsiadujących z klikniętą
  // sprawdzamy odsuniecie od gory żeby nie próbować zmeniać stanu nieistniejących lampek
  if rzad>0 then
  begin
    // jeśli lampka była zapalona
    if Zapalona[rzad-1, kolumna] = True then
    // zgaś ją
    begin
      Zapalona[rzad-1, kolumna]:= False;
      Obrazki.GetBitmap(0, Lampki[rzad-1, kolumna].Picture.Bitmap);
    end
    else
    // lub zapal jeśli była zgaszona
    begin
      Zapalona[rzad-1, kolumna]:= True;
      Obrazki.GetBitmap(1, Lampki[rzad-1, kolumna].Picture.Bitmap);
    end;
  end;

  // sprawdzamy odsuniecie od dolu
  if rzad<4 then
  begin
    if Zapalona[rzad+1, kolumna] = True then
    begin
      Zapalona[rzad+1, kolumna]:= False;
      Obrazki.GetBitmap(0, Lampki[rzad+1, kolumna].Picture.Bitmap);
    end
    else
    begin
      Zapalona[rzad+1, kolumna]:= True;
      Obrazki.GetBitmap(1, Lampki[rzad+1, kolumna].Picture.Bitmap);
    end;
  end;

  // sprawdzamy odsuniecie od lewej
  if kolumna>0 then
  begin
    if Zapalona[rzad, kolumna-1] = True then
    begin
      Zapalona[rzad, kolumna-1]:= False;
      Obrazki.GetBitmap(0, Lampki[rzad, kolumna-1].Picture.Bitmap);
    end
    else
    begin
      Zapalona[rzad, kolumna-1]:= True;
      Obrazki.GetBitmap(1, Lampki[rzad, kolumna-1].Picture.Bitmap);
    end;
  end;

  // sprawdzamy odsuniecie od prawej
  if kolumna<4 then
  begin
    if Zapalona[rzad, kolumna+1] = True then
    begin
      Zapalona[rzad, kolumna+1]:= False;
      Obrazki.GetBitmap(0, Lampki[rzad, kolumna+1].Picture.Bitmap);
    end
    else
    begin
      Zapalona[rzad, kolumna+1]:= True;
      Obrazki.GetBitmap(1, Lampki[rzad, kolumna+1].Picture.Bitmap);
    end;
  end;

  // obsługa klikniętej lampki
  if Zapalona[rzad, kolumna] = True then
  begin
    Zapalona[rzad, kolumna]:= False;
    Obrazki.GetBitmap(0, Lampki[rzad, kolumna].Picture.Bitmap);
  end
  else
  begin
    Zapalona[rzad, kolumna]:= True;
    Obrazki.GetBitmap(1, Lampki[rzad, kolumna].Picture.Bitmap);
  end;
end;

initialization
  {$I swiatelka.lrs}

end.

