/* Datei: v3_dialo.c            */
/* P. Rieger; TUD/PLT 4.10.2001 */

/*****************************************************************************

  Praktikumsversuch: Einführung in die Sprache C
  Programm-Modul "Parameterdialog"

*****************************************************************************/

#include "dialog.h"
#include <stdio.h>
#include <stdlib.h>

/*--- Definitionen ---------------------------------------------------------*/

typedef enum {FALSE, TRUE} bool;


/*--- Tastatureingabe lesen und nur ersten Character beachten --------------*/

char InputChar ()
{
	char s[80];
  	fgets(s,sizeof(s), stdin);
  	return s[0];
};

/*--- Double-Zahl von der Tastatur lesen -----------------------------------*/

void InputDouble (double *value)
{
  	char *endptr;
  	char s[80];
  	fgets(s,sizeof(s), stdin);
  	if (s[0]!=10) *value=strtod (s, &endptr);
};


/*--- Int-Zahl von der Tastatur lesen --------------------------------------*/

void InputInt (int *value)
{
  char s[80];
  fgets(s,sizeof(s), stdin);
  if (s[0]!=10) *value=atoi (s);
};


/*---Auflisten der aktuellen Parameter-----------------------------*/

void ShowParameters ( tParam p,tComplex c)
{
	printf("0 Radius R			%f\n",p.R);
	printf("1 Iterationsgrenze		%i\n",p.imax);
	printf("2 Komplexe Zahl Realteil		%f\n",c.Re);
	printf("3 Komplexe Zahl Imaginaerteil	%f\n",c.Im);
	printf("4 Fraktaltyp			%i\n",p.ftype);
	printf("5 X min				%f\n",p.xmin);
	printf("6 X max				%f\n",p.xmax);
	printf("7 Y min				%f\n",p.ymin);
	printf("8 Y max				%f\n",p.ymax);
	printf("9 Auflösung der X Achse		%i\n",p.xpoints);
	printf("10 Auflösung der Y Achse	%i\n",p.ypoints);
	printf("11 Fraktal erstellen		\n");
	printf("12 Programm beenden		\n");
}


void ShowParameters ( tParam p,tComplex c)
{
	printf("0 Radius R			\n",p.R);
	printf("1 Iterationsgrenze		\n",p.imax);
	printf("2 Komplexe Zahl Realteil		\n",c.Re);
	printf("3 Komplexe Zahl Imaginärteil	\n",c.Im);
	printf("4 Fraktaltyp			\n",p.ftype);
	printf("5 X min				\n",p.xmin);
	printf("6 X max				\n",p.xmax);
	printf("7 Y min				\n",p.ymin);
	printf("8 Y max				\n",p.ymax);
	printf("9 Auflösung der X Achse		\n",p.xpoints);
	printf("10 Auflösung der Y Achse	\n",p.ypoints);
	printf("11 Fraktal erstellen		\n");
	printf("12 Programm beenden		\n");
}

double ShowRadius ()
{
	unsigned double radius;

	printf("Geben Sie den gewünschten Radius an: ");
	scanf("%lf",&radius);

	return radius;
}

tFractalType ShowFractType ()
{
	int fractaltype;
	do
	{
		printf("Wählen Sie den Fraktaltyp aus : 0 für Apfelmännchen / 1 für Juliamenge");
		scanf("%i",&fractaltype);
	} while ((fractaltype != 0)&&(fractaltype != 1));

	return fractaltype;
}

double ShowRealteil ()
{
	double real;

	printf("Geben Sie den gewünschten Realteil der komplexen Zahl an : ");
	scanf("%lf",&real);

	return real;
}

double ShowImaginaerteil ()
{
	double imaginaer;

	printf("Geben Sie den gewünschten Imaginärteil der komplexen Zahl an :");
	scanf("%lf",&imaginaer);

	return imaginaer;
}

int ShowImax ()
{
	unsigned int itergr;

	printf("Geben Sie die gewünschte Integrationsgrenze an :");
	scanf("%d", &itergr);

	return itergr;

}

double ShowXmax(double Xmax)
{
	double Xmin;
	do
	{
		printf("Geben Sie den minimalen X Wert an :");
		scanf("%lf",&Xmin);
	}while (Xmin >= Xmax);

	return Xmin;
}

double ShowXmin(double Xmin)
{
	double Xmax;
	do
	{
		printf("Geben Sie den maximalen X Wert an :");
		scanf("%lf",&Xmax);
	}while (Xmax <= Xmin);

	return Xmax;
}

double ShowYmax(double Ymax)
{
	double Ymin;
	do
	{
		printf("Geben Sie den minimalen Y Wert an :");
		scanf("%lf",&Ymin);
	}while (Ymin >= Ymax);

	return Ymin;
}

double ShowYmin(double Ymin)
{
	double Ymax;
	do
	{
		printf("Geben Sie den maximalen Y Wert an :");
		scanf("%lf",&Ymax);
	}while (Ymax <= Ymin);

	return Ymax;
}

double ShowXpoints ()
{
	unsigned double Xpoints;

	printf("Geben Sie die gewünschte Auflösung der X Achse an :");
	scanf("%lf",&Xpoints);

	return Xpoints;

}

double ShowYpoints ()
{
	unsigned double Ypoints;

	printf("Geben Sie die gewünschte Auflösung der Y Achse an :");
	scanf("%lf",&Ypoints);

	return Ypoints;

}



/*--- Parameter Dialog ------------------------------------------------------*/

int ParamDialog (tParam *p, tComplex *c)
{
	tParam p1=*p;
	tComplex c1=*c;
	int Parameternummer;

	do
	{
		ListParameters 	(p1,c1);			// Anzeige der bisherigen Parameter
		printf("Welchen Parameter möchten Sie aendern ? \n");
		scanf("%i" , &Parameternummer);		// Einlesen des ausgewählten Parameters
		switch (Parameternummer)
		{
			case 0: p1.R = ShowRadius ();	break;		// Radius R ändern
			case 1: p1.imax = ShowImax();	break;		// Iterationsgrenze verändern
			case 2:	c1.Re = ShowRealteil();	break;
			case 3: c1.Im = ShowImaginaerteil();	break;
			case 4: p1.ftype = ShowFractType ();	break;		// Fraktaltyp verändern
			case 5: p1.xmin = ShowXmin();	break;		// Anfangswert der X Achse ändern
			case 6: p1.xmax = ShowXmax();	break;		//
			case 7: p1.ymin = ShowYmin();	break;
			case 8: p1.ymax = ShowYmax();	break;
			case 9: p1.xpoints = ShowXpoints();	break;
			case 10: p1.ypoints = ShowYpoints();	break;
			case 11:				break;
			case 12: printf("Programmende\n");	break;
			default: printf("Dieser Parameter existiert nicht\n");	break;
		}
	}while ((Parameternummer!=11)&&(Parameternummer!=12));

		*p = p1;				// Abspeichern der veränderten Parameter
		*c = c1;
		return (Parameternummer!=12);	// Wenn das Programm beendet wird ist Rückgabewert 0
}


/* v3_frakt.c */

