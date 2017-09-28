#include "metode.h"

ElementListe* pocetak;

void ispisiListu()
{
    ElementListe* trenutni = pocetak;
    bool end = false;

    if (pocetak == NULL)
    {
        printf("Lista je prazna.\n");
        return;
    }

    else {

        do
        {
            printf("\n\tEvidencioni broj: \t%d", trenutni->komad.evidencioni_broj);
            printf("\n\tVrsta namestaja: \t\t%s", trenutni->komad.vrstaNamestaja);
            printf("\n\tDatum proizvodnje: \t\t%d", trenutni->komad.dvp.dan, ".%d", trenutni->komad.dvp.mesec, ".%d", trenutni->komad.dvp.godina, ".");
            printf("\n\tVreme proizvodnje: \t\t%d", trenutni->komad.dvp.sati, ":%d", trenutni->komad.dvp.minuti);
            printf("\n\tNaziv modela: \t%s", trenutni->komad.nazivModela);
            printf("\n\tTezina: \t%d\n", trenutni->komad.tezina);

            if (trenutni->sledeci == NULL)
            {
                end = true;
                return;
            }

            trenutni = trenutni->sledeci;

        } while (end == false);

    }
}



