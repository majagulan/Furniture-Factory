#include "metode.h"

void izborAktivneDatoteke(Datoteka* aktivna) {

    Datoteka dat;

    if (dat.otvorena)
        printf("\nDatoteka '%s' je vec aktivirana.\n", dat.ime);

    printf("\nUnesite ime datoteke: ");
    fflush(stdin);
    gets(dat.ime);

    dat.file = fopen(dat.ime, "r+b");

    if (dat.file != NULL)
    {
        if(aktivna->file != NULL)
            fclose(aktivna->file);

        aktivna->file = dat.file;

        memcpy(aktivna->ime, dat.ime, MAX_NAZIV_DAT);
        printf("\nDatoteka '%s' je uspesno aktivirana\n",dat.ime);
        dat.otvorena = true;
    }

    else if(dat.file == NULL)
    {
        printf("\nGreska, ne postoji datoteka sa nazivom '%s' \n", dat.ime);
        dat.otvorena = false;

    }

}
