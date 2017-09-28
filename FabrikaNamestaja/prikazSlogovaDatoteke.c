#include "metode.h"

//stampa se sadrzaj svih slogova u baketima

void prikazSlogovaDatoteke(Datoteka* aktivna) {

    Baket baket;

    if (!(aktivna->otvorena))
        printf("\nNe postoji aktivna datoteka.\n");

    else
    {
        int trenutniBaket = 1;
        while(trenutniBaket < B) //treba <= B!!!!!
        {
            nadjiBaket(aktivna, trenutniBaket, &baket);
            int j = 0;
            while (j < b)
            {
                if(baket.slog[j].status == AKTIVAN)
                {
                    printf("\n\nAdresa baketa je: %d", trenutniBaket);
                    printf("\nRedni broj sloga u baketu je: %d", j+1);

                    printf("\n\nEvidencioni broj: %d", baket.slog[j].evidencioni_broj);
                    printf("\nVrsta namestaja: %s", baket.slog[j].vrstaNamestaja);
                    printf("\nDatum proizvodnje: %d/%d/%d", baket.slog[j].dvp.dan, baket.slog[j].dvp.mesec, baket.slog[j].dvp.godina);
                    printf("\nVreme proizvodnje: %d:%d", baket.slog[j].dvp.sati, baket.slog[j].dvp.minuti);
                    printf("\nNaziv modela: %s", baket.slog[j].nazivModela);
                    printf("\nTezina: %d\n", baket.slog[j].tezina);
                }
                j++;
            }
            trenutniBaket++;
        }
    }
}
