#include "metode.h"

void prikazNazivaAktivneDatoteke(Datoteka* aktivna){

    if(aktivna->file == NULL)
		printf("\nNe postoji aktivna datoteka\n\n");
	else
		printf("Aktivna datoteka je: '%s'.\n\n", aktivna->ime);
}
