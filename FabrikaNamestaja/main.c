#include <stdio.h>
#include <stdlib.h>

#include "metode.h"

int main()
{
    int odg = 0;

    Datoteka aktivna;
    aktivna.file = NULL;
    printf("******* Fabrika namestaja GRAD *******\n\n\n");

    do
    {
        do {
            odg = menu();
        } while (odg < 0 || odg > 8);


        if (odg == 1)
            formiranjePrazneDatoteke();
        else if (odg == 2)
            izborAktivneDatoteke(&aktivna);
        else if (odg == 3)
            prikazNazivaAktivneDatoteke(&aktivna);
        else if (odg == 4)
            upisNovogSlogaUDatoteku(&aktivna);
        else if (odg == 5)
            prikazSlogovaDatoteke(&aktivna);
        else if (odg == 6)
            logickoBrisanje(&aktivna);
        else if (odg == 7)
            ucitajSortirajPrikaziPoTezini(&aktivna);
        else if (odg == 8)
        {
            fflush(aktivna.file);
            fclose(aktivna.file);
            exit(0);
        }

    } while(odg != 8);

    return 0;

}

