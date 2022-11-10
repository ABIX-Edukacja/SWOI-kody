unit wieze_hanoi;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, FileUtil, LResources, Forms, Controls, Graphics, Dialogs,
  ExtCtrls;

type

  { TOkno }

  TOkno = class(TForm)
    Krazek1: TImage;
    Krazek2: TImage;
    Krazek3: TImage;
    Krazek4: TImage;
    Krazek5: TImage;
    Timer1: TTimer;
    procedure FormCreate(Sender: TObject);
    procedure Timer1Timer(Sender: TObject);
  private
    { private declarations }
    ileP: array[0..2] of Integer;
    pozP: array[1..5] of Integer;
    i: Integer;
  public
    { public declarations }
  end; 

var
  Okno: TOkno;

implementation

{ TOkno }

procedure TOkno.FormCreate(Sender: TObject);
begin
  ileP[0]:= 5;
  ileP[1]:= 0;
  ileP[2]:= 0;
  pozP[1]:= 0;
  pozP[2]:= 0;
  pozP[3]:= 0;
  pozP[4]:= 0;
  pozP[5]:= 0;
end;

procedure TOkno.Timer1Timer(Sender: TObject); { procedura wywoływana cyklicznie na sygnał Timera, taka sama jak w implementacji w VisualBasic'u }
begin
  i:= i+1;
  if((i-1) mod 2)=0 then
  begin
    ileP[pozP[1]]:= ileP[pozP[1]]-1;
    pozP[1]:= pozP[1]-1;
    if pozP[1]<0 then pozP[1]:= 2;
    ileP[pozP[1]]:= ileP[pozP[1]]+1;
    Krazek1.Left:= 50 + pozP[1] * 250;
    Krazek1.Top:= 270 - ileP[pozP[1]] * 50;
  end
  else if((i-16) mod 32)=0 then
  begin
    ileP[pozP[5]]:= ileP[pozP[5]]-1;
    pozP[5]:= pozP[5]-1;
    if pozP[5]<0 then pozP[5]:= 2;
    ileP[pozP[5]]:= ileP[pozP[5]]+1;
    Krazek5.Left:= 50 + pozP[5] * 250;
    Krazek5.Top:= 270 - ileP[pozP[5]] * 50;
  end
  else if((i-8) mod 16)=0 then
  begin
    ileP[pozP[4]]:= ileP[pozP[4]]-1;
    pozP[4]:= pozP[4]+1;
    if pozP[4]>2 then pozP[4]:= 0;
    ileP[pozP[4]]:= ileP[pozP[4]]+1;
    Krazek4.Left:= 50 + pozP[4] * 250;
    Krazek4.Top:= 270 - ileP[pozP[4]] * 50;
  end
  else if((i-4) mod 8)=0 then
  begin
    ileP[pozP[3]]:= ileP[pozP[3]]-1;
    pozP[3]:=pozP[3]-1;
    if pozP[3]<0 then pozP[3]:= 2;
    ileP[pozP[3]]:= ileP[pozP[3]]+1;
    Krazek3.Left:= 50 + pozP[3] * 250;
    Krazek3.Top:= 270 - ileP[pozP[3]] * 50;
  end
  else if((i-2) mod 4)=0 then
  begin
    ileP[pozP[2]]:= ileP[pozP[2]]-1;
    pozP[2]:= pozP[2]+1;
    if pozP[2]>2 then pozP[2]:= 0;
    ileP[pozP[2]]:= ileP[pozP[2]]+1;
    Krazek2.Left:= 50 + pozP[2] * 250;
    Krazek2.Top:= 270 - ileP[pozP[2]] * 50;
  end;
  if ileP[2]=5 then Timer1.Enabled:=False;
end;

initialization
  {$I wieze_hanoi.lrs}

end.

