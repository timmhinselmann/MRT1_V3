/* Datei: v3_frakt.c              */
/* De Gortari, Miersch, Hinselmann, Kierstein   */

/*****************************************************************************

  Praktikumsversuch: Einführung in die Sprache C
  Programm-Modul "Fraktal-Analyse"

*****************************************************************************/

#include "fraktal.h"
#include "graphic.h"
#include <stdio.h>


/*--- Weitere Interne Funktionen -------------------------------------------*/

double quadrat (double a)
{
	return a*a;
}

/*--- Interne Funktion: Analyse der Iterationsanzahl -----------------------*/

int GetItera (tComplex c, tComplex z, tParam p)
{
	tComplex z_i1;			// Deklaration von z_i+1
	tComplex z_i;			// und z_i
	tComplex z_0;			// Anfangswert der Iteration

	int i = 0;				// Deklaration vom Iterationszähler
	double Abstand = 0;		// Betrag des Punktes zum Nullpunkt
	double h1 = 0;
	double h2 = 0;
							// wird anfangs auf 0 gesetzt
	if (p.ftype == Apfelmaennchen)	// Durch die if Abfrage wird der Typ des Fraktals abgefragt
	{ 						// je nach Typ wird dann der Anfangswert der Iteration entweder
		z_0 = c;			// durch c oder z bestimmt
	}

	if (p.ftype == Juliamenge)
	{
		z_0 = z;
	}

	z_i = z;			// Am Anfang der Berechnung wird z_i+1 auf z gesetzt

	while ( (i < p.imax) && (Abstand <= p.R) )
	{
		z_i1.Re = c.Re + quadrat(z.Re) - quadrat(z.Im); 	// Realteil von z_i+1
		z_i1.Im = c.Im - 2*z.Re*z.Im;				// Imaginärteil von z_i+1

		z_i = z_i1;						// z_i+1 auf z_i setzen

		h1 = z_0.Re - z_i.Re;					// Hilfswerte für Abstandsberechnung
		h2 = z_0.Im - z_i.Im;					// a = x0-xi  b = yo-yi
		Abstand = sqrt(quadrat(h1) + quadrat(h2));		// Abstandsberechnung

		i++;							// Erhöhen des Iterationszählers
	}

	return i;
}

/*--- Interne Funktion: Farbwert bestimmen ---------------------------------*/

tColor GetColorValue (int i, int imax)
{
	tColor color;					// Erstellen einer Variablen für die Farbe
	int a = 0;

	switch (i%15)					// Durch Moduloanweisung wird die Farbauswahl
	{								// mit dem Restsystem bestimmt
		case 0:	a = 1;	break;
		case 1:	a = 2;	break;
		case 2:	a = 3;	break;
		case 3:	a = 4;	break;
		case 4:	a = 5;	break;
		case 5:	a = 6;	break;
		case 6:	a = 7;	break;
		case 7:	a = 8;	break;
		case 8:	a = 9;	break;
		case 9:	a = 10;	break;
		case 10:a = 11;	break;
		case 11:a = 12;	break;
		case 12:a = 13;	break;
		case 13:a = 14;	break;
		case 14:a = 15;	break;
	}
	if (i==imax) a=0;				// Wenn das Gebiet nicht verlassen wird wird
							// die Farbe Schwarz ausgewählt
	return (tColor) a;				// Ausgabe der Farbe die an a-ter Stelle in der
							// graphic.h Datei implementiert ist
}


/*--- Fraktal-Figur analysieren und zeichnen -------------------------------*/

void Fraktal (tComplex c, tComplex z, tParam p)
{

	double x;				// Anfangswerte für die Pixelzuweisung
	double y;
	int i;						// Iterationszähler
	tColor colour;					// Farbe des Pixels

	for (x=p.xmin;x<p.xmax;x=x+((p.xmax-p.xmin)/640))	// Iteration von xmin nach xmax in 640
								// Schritten
	{
		for (y=p.ymin;y<p.ymax;y=y+((p.ymax-p.ymin)/480))	// Zweite Schleife um y abzuarbeiten
		{
			tComplex u = {x,y};
			if (p.ftype == Apfelmaennchen) 	{i = GetItera (u, z,p);}	// Variation von c
			if (p.ftype == Juliamenge)	{i = GetItera (c, u, p);}	// Variation von z

			colour = GetColorValue(i,p.imax);	// Farbe bestimmen

			SetPoint (x,y,colour);			// Farbpunkt setzten
		}
	}
}


/* v3_frakt.c */

