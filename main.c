/* Datei v3_main.c              */
/* De Gortari, Miersch, Hinselmann, Kierstein */

/*****************************************************************************

  Praktikumsversuch: Einfuehrung in die Sprache C
  Main-Programm

*****************************************************************************/

#include "fraktal.h"
#include "graphic.h"
#include "dialog.h"
#include <stdio.h>

int a;
int abbruch;

int main (void)
{
	/*--- Variablendeklaration ---------------------------------------------*/

	struct tParam InitParam =		// Vorinitialisierung
	{
		4, 75, Apfelmaennchen, -2, 2, -2, 2, 640, 480
	};

  	/*--- Initialwerte -----------------------------------------------------*/

	tComplex c1 = {0.4,0.4};
	tComplex z1 = {-0.0,-0.0};

  	/*----------------------------------------------------------------------*/
  	/*--- Parameter ueber Dialog abfragen                                  --*/
  	/*----------------------------------------------------------------------*/

	while (ParamDialog (&InitParam,&c1))
	{
		InitGraph (InitParam.xmin, InitParam.xmax, InitParam.ymin, InitParam.ymax); 	// Initialisierung der Grafik

		LockScreen(); // Bildschirm muss zum Setzen von Pixeln gesperrt sein

	/*----------------------------------------------------------------------*/
  	/*--- Fraktale berechnen und ausgeben                                 --*/
  	/*----------------------------------------------------------------------*/
		Fraktal (c1,z1,InitParam);				// Fraktalberechnung

		UnlockScreen(); // Alle aenderungen auf Bildschirm ausgeben

	/*Aufrufen von InputChar() um das Programm nach dem oeffnen der Graphik   */
    	/*anzuhalten. Erst wenn in der Konsole eine Taste gedrueckt wird, schließt*/
    	/*sich das Fenster wieder. */
		InputChar();				// Warten auf eine Tastatureingabe
		CloseGraph();					// Graphikfenster beenden
	}
    return 0;
}
