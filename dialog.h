/* Datei: v3_dialo.h              */
/* De Gortari, Miersch, Hinselmann, Kierstein   */

/*****************************************************************************

  Praktikumsversuch: Einführung in die Sprache C
  Programm-Modul "Parameterdialog"

*****************************************************************************/

#ifndef __dialog
#define __dialog

#include "fraktal.h"

/*--- Funktionen zum Auslesen der angeforderten Parameter-------------------*/

tComplex ShowComplex();
double ShowRadius();
int ShowImax();
tFractalType ShowFractType();
double ShowXmin(double Xmin);
double ShowXmax(double Xmax);
double ShowYmin(double Ymin);
double ShowYmax(double Ymax);
int ShowXpoints();
int ShowYpoints();

/*--- Parameter Dialog Prototyp --------------------------------------------*/

int ParamDialog (tParam p ,tParam c);

void ShowParameters (tParam p,tComplex c);


/*--- Funktion zum einlesen des ersten Characters einer getchar() Eingabe --*/
char InputChar();
void InputDouble (double *value);
void InputInt (int *value);

#endif

/* v3_dialo.h */

