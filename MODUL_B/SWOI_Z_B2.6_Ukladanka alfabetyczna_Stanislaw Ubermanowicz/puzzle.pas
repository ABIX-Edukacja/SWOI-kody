unit puzzle;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, FileUtil, LResources, Forms, Controls, Graphics, Dialogs,
  Menus, StdCtrls, ExtCtrls;

type

  { TOkno }

  TOkno = class(TForm)
    Label1: TLabel;
    MainMenu1: TMainMenu;
    MenuItem1: TMenuItem;
    MenuItem2: TMenuItem;
    MenuItem3: TMenuItem;
    MenuItem4: TMenuItem;
    MenuItem5: TMenuItem;
    MenuItem6: TMenuItem;
    procedure FormCreate(Sender: TObject);
    procedure ClickAction(Sender: TObject);
    procedure MoveAction(nadawca: Integer);
    procedure SprawdzKoniec();
    procedure Rozrzuc(Sender: TObject);
    procedure Uloz(Sender: TObject);
  private
    { private declarations }
    kafelki: array[0..4, 0..4] of TPanel;
    nadawca: Integer;
  public
    { public declarations }
  end; 

var
  Okno: TOkno;
  r, k, i: Integer;

implementation

{ TOkno }

procedure TOkno.FormCreate(Sender: TObject);
begin
  Label1.Visible:= False; { ukryj napis o wygranej }

  for r:= 0 to 4 do { przemieszczaj się po rzędach w tablicy }
  begin
    for k:= 0 to 4 do { przemieszczaj się po kolumnach w tablicy }
    begin
      kafelki[r, k]:= TPanel.Create(self); { stwórz wszystkie elementy }
      kafelki[r, k].Parent:= self; { przypisz je do okna }
      kafelki[r, k].Height:= 60; { określ ich wysokość }
      kafelki[r, k].Width:= 60; { określ szerokość }
      kafelki[r, k].Caption:= Char(r*5+k+65); { Ustawienie napisu na kafelku z kodu ASCII }
      if (r*5+k)=24 then kafelki[r, k].Caption:= ''; { Ustawienie opisu ostatniego kafelka na pusty }
      kafelki[r, k].Font.Size:= 34; { Ustawienie wielkości czcionki }
      kafelki[r, k].BorderWidth:= 5; { Ustawienie rozmiaru ramki kafelka }
      kafelki[r, k].BorderStyle:= bsSingle; { oraz stylu ramki kafelka }
      kafelki[r, k].Top:= r*60; { ustaw obiekt w odpowiednik miejscu w oknie }
      kafelki[r, k].Left:= k*60; { ustaw obiekt w odpowiednik miejscu w oknie }
      kafelki[r, k].Tag:= r*5+k; { przypisz obiektowi odpowiednik numer porządkowy }
      kafelki[r, k].OnClick:= @ClickAction; { przypisz która funkcja ma reagować na kliknięie w obiekt }
    end;
  end;
end;

procedure TOkno.ClickAction(Sender: TObject); { procedura obsługująca kliknięcie }
begin
  { przekształć typ ogólny Sender na obiekt TPanel i pobierz do zmiennej wartość numeru porządkowego }
  nadawca:= (Sender as TPanel).Tag;
  MoveAction(nadawca); { przekaż pobrany numer porzadkowy do procedury MoveAction }
  SprawdzKoniec(); { sprawdź czy elementy zostały ułożone w prawidłowej kolejności }
end;

procedure TOkno.MoveAction(nadawca: Integer); { procedura przemieszczania elementów }
begin
  for r:= 0 to 4 do { przejdź przez wszystkie rzędy }
  begin
    for k:=0 to 4 do { oraz wszystkie kolumny }
    begin
      if kafelki[r, k].Tag=nadawca then { w poszukiwaniu elementu który został kliknięty (poszukujemy go aby poznać jego koordynaty) }
      begin
        { analiza zawartości i zakresów macierzy}
        if (r > 0) and (kafelki[r-1, k].Caption = '') then
        begin
          kafelki[r-1, k].Tag:= kafelki[r, k].Tag;
          kafelki[r-1, k].Caption:= kafelki[r, k].Caption;
          kafelki[r, k].Tag:= 24;
          kafelki[r, k].Caption:= '';
        end
        else if (r < 4) and (kafelki[r+1, k].Caption = '') then
        begin
          kafelki[r+1, k].Tag:= kafelki[r, k].Tag;
          kafelki[r+1, k].Caption:= kafelki[r, k].Caption;
          kafelki[r, k].Tag:= 24;
          kafelki[r, k].Caption:= '';
        end
        else if (k > 0) and (kafelki[r, k-1].Caption = '') then
        begin
          kafelki[r, k-1].Tag:= kafelki[r, k].Tag;
          kafelki[r, k-1].Caption:= kafelki[r, k].Caption;
          kafelki[r, k].Tag:= 24;
          kafelki[r, k].Caption:= '';
        end
        else if (k < 4) and (kafelki[r, k+1].Caption = '') then
        begin
          kafelki[r, k+1].Tag:= kafelki[r, k].Tag;
          kafelki[r, k+1].Caption:= kafelki[r, k].Caption;
          kafelki[r, k].Tag:= 24;
          kafelki[r, k].Caption:= '';
        end;
        Exit(); { po przemieszczeniu elementów wyjdź z funkcji }
      end;
    end;
  end;
end;

procedure TOkno.SprawdzKoniec(); { procedura sprawdzająca czy wszystkie elementy tablicy są ułożone we właściwej kolejności }
begin
  for k:= 0 to 23 do { przez całą tablicę z wyjątkiem ostatniego pola }
  begin
    i:=k+65; { wylicz kod litery którą powinno mieć to pole }
    if Char(i)<>kafelki[k div 5, k mod 5].Caption then { jeśli litera nie odpowiada tej która powinna tam być - kolejność się nie zgadza }
    begin
      Label1.Visible:= False; { ukryj napis o wygranej }
      Exit(); { wyjdź z funkcji }
    end;
  end;
  Label1.Visible:= True; { jeśli kolejność się zgadza to pokaż napis }
end;

procedure TOkno.Rozrzuc(Sender: TObject); { procedura rozrzucająca elementy }
var
  ilosc: Integer; { zmienna lokalna dla tej procedury }
begin
  Randomize(); { ustal ziarno generatora liczb losowych }
  Label1.Visible:= False; { ukryj napis }
  nadawca:= (Sender as TMenuItem).Tag; { pobierz wartość numeru porządkowego }
  if nadawca=0 then ilosc:= 200 { zaleznie od jego wartości ustal liczbę przemieszczeń }
  else if nadawca=1 then ilosc:= 1000
  else if nadawca=2 then ilosc:= 5000;

  for i:= 0 to ilosc do { określoną ilośc razy }
    MoveAction(Random(25)); { przemieść losowy element }
end;

procedure TOkno.Uloz(Sender: TObject); { procedura układająca wszystkie elementy w prawidłowej kolejności }
begin
  for r:= 0 to 4 do { przejdź przez wszystkie rzędy }
  begin
    for k:= 0 to 4 do { i przez wszystkie kolumny }
    begin
      kafelki[r, k].Caption:= Char(r*5+k+65); {przypisz kolejne litery}
      if (r*5+k)=24 then kafelki[r, k].Caption:= ''; {jeśli to ostatni kafelek ustaw puste pole}
      kafelki[r, k].Tag:= r*5+k; { ustaw kolejne numery porzadkowe }
    end;
  end;
end;

initialization
  {$I puzzle.lrs}

end.

