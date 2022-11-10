program projekt;

{$mode objfpc}{$H+}

uses
  {$IFDEF UNIX}{$IFDEF UseCThreads}
  cthreads,
  {$ENDIF}{$ENDIF}
  Interfaces, // this includes the LCL widgetset
  Forms, puzzle, LResources
  { you can add units after this };

{$IFDEF WINDOWS}{$R projekt.rc}{$ENDIF}

begin
  {$I projekt.lrs}
  Application.Initialize;
  Application.CreateForm(TOkno, Okno);
  Application.Run;
end.

