unit Unit1;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, FileUtil, Forms, Controls, Graphics, Dialogs, ExtCtrls;

type

  { TKiK }

  TKiK = class(TForm)
    // obiekty umieszczone an planszy
    Image1: TImage;
    Image2: TImage;
    Image3: TImage;
    Image4: TImage;
    Image5: TImage;
    Image6: TImage;
    Image7: TImage;
    Image8: TImage;
    Image9: TImage;
    ImageList1: TImageList;
    // procedury używane w programie
    procedure FormCreate(Sender: TObject);
    procedure Image1Click(Sender: TObject);
  private
    tura: Integer;  // zmienna zliczająca tury
  public
    { public declarations }
  end;

var
  KiK: TKiK;

implementation

{$R *.lfm}

// procedura wywoływana podczas startu programu
procedure TKiK.FormCreate(Sender: TObject);
begin
  tura := 0;  // wyzerowanie licznika tur
end;

// procedura wywoływana w momencie kliknięcia w kafelek
procedure TKiK.Image1Click(Sender: TObject);
var
  klikniety: TImage;  // zmienna do przechowywania informacji który kafelek został kliknięty
  wybieracz: Integer;  // zmienna przechowująca informację o tym jaki element umieścić
begin
  klikniety := (Sender as TImage);  // przypisanie klikniętego elementu do zmiennego
  wybieracz := tura mod 2;  // określenie jaki obiekt teraz umieścić
  if klikniety.Tag = 0 then  // sprawdzenie czy kafelek nie był już wcześniej kliknięty
  begin
    ImageList1.GetBitmap(wybieracz, klikniety.Picture.Bitmap);  // przypisanie odpowiedniego obrazka do kafelka
    klikniety.Tag := 1;  // zapisanie informacji, że kafelek został kliknięty
    tura := tura + 1;  // zwiększenie licznika tur
  end;
end;

end.

