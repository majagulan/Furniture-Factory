#include "metode.h"

void logickoBrisanje(Datoteka* aktivna) {

    Baket baket;

    if (aktivna->file == NULL)
        printf("\n\nNe postoji aktivna datoteka.\n\n");

    else
    {
        int trenutniBaket = 1;
        while(trenutniBaket < B)
        {
            nadjiBaket(aktivna, trenutniBaket, &baket);
            int j = 0;
            while (j < b)
            {
                if(baket.slog[j].status == AKTIVAN)
                {
                    //brisemo sve
                    baket.slog[j].status = SLOBODAN;
                    upisiBaket(aktivna, trenutniBaket, &baket);
                }
                j++;
            }
            trenutniBaket++;
        }
        printf("\n\nSvi aktuelni slogovi iz aktivne datoteke su obrisani\n\n");
    }
}
