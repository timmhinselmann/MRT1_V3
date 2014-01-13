
/*****************************************************************************

  Praktikumsversuch: Einführung in die Sprache C
  Programm-Modul "Fraktal-Analyse"

*****************************************************************************/

#ifndef __fraktal
#define __fraktal

/*--- Datentypvereinbarungen -----------------------------------------------*/

typedef enum { Apfelmaennchen, Juliamenge } tFractalType;	// Enumerationstyp zur Auswahl zwischen Apfelmnnchen und

typedef struct tParam {			// Definition des neuen Datentypen tParam in dem die zur Berechnung nötigen Datenelemente zusammengefasst sind
	double R;					// Radius R zur Beschreibung des kreisförmigen Gebietes der komplexen Zahl
	int imax;					// imax zur Beschreibung der maximalen Iterationszahl
	tFractalType ftype;			// Enumerationstyp für die Fraktalvarianten Apfelmännchen oder Juliamenge
	double xmin;				// Kennzeichnung des komplexwertigen Analysegebietes
	double xmax;
	double ymin;
	double ymax;
	int xpoints;				// Anzahl für die Linien im Analysegebiet (Pixel horizontal)
	int ypoints;				// Anzahl der Pixel (vertikal)
}tParam;						// Semikolon nach dem Anweisungsblock nicht vergessen


typedef struct tComplex {		// Struktur tComplex zur Beschreibung der komplexen Zahlen in Kartesischen 					// Koordinaten
double Re;				// Realteil der komplexen Zahl
double Im;				// Imaginärteil der komplexen Zahl

}tComplex;

/*--- Fraktal analysieren und grafisch darstellen --------------------------*/

int GetItera (tComplex c, tComplex z, tParam p);			// Iteration berechnen
tColor GetColorValue (int i, int imax);						// Farbe auswählen
void Fraktal (tComplex c, tComplex z, tParam p);			// Fraktal zeichnen

#endif

/* v3_frakt.h */
