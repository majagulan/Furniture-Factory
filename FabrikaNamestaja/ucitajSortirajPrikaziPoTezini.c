#include "metode.h"

void ucitajSortirajPrikaziPoTezini (Datoteka* aktivna) {

    Baket bak;
    int donjaGranica;
    int i, j;

    if (aktivna->file == NULL)
    {
        printf("\n\nNe postoji aktivna datoteka.\n\n");
        return;
    }

    else
    {
        printf("Unesite donju granicu tezine: \t\t");
        scanf("%d", &donjaGranica);

        printf("\nUcitavanje slogova sa tezinom vecom od %d\n", donjaGranica);

        // B je broj baketa iz strukture.h
        for(i = 1; i <= B; i++) {
            nadjiBaket(aktivna, i, &bak);
            // b je faktor baketiranja iz strukture.h
            for(j = 0; j < b; j++)
            {
                if(bak.slog[j].status == AKTIVAN)
                    if(bak.slog[j].tezina > donjaGranica)
                        dodajISortirajListu(bak.slog[j]);
            }
        }

        ispisiListu();
        isprazniListu();

    }
}
