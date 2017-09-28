#include "metode.h"

int daLiSlogPostoji(Datoteka* aktivna, int kljuc) {

    int i = 0;
    Baket baket;
    int maticniBaket, trenutniBaket;

    trenutniBaket = kljuc % B + 1;
    maticniBaket = trenutniBaket;

    while (maticniBaket == trenutniBaket)
    {
        //trazi se logicki naredni
        nadjiBaket(aktivna, trenutniBaket, &baket);

        do {
            if(baket.slog[i].status == AKTIVAN && baket.slog[i].evidencioni_broj == kljuc)
                return 1;
             i++;
        } while (i < b);

        trenutniBaket = trenutniBaket + k;

        //trazennje linearnom metodom sa fiksnim korakom k
        if(trenutniBaket > B)
            trenutniBaket = trenutniBaket % B;
    }

    return 0;
}

