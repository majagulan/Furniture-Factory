#include "metode.h"

void nadjiBaket(Datoteka* dat, unsigned int adresa, Baket* baket){
    int idx;

    if(adresa < 1 || adresa > B)
    {
        printf("\nNepostojeca adresa baketa.\n");
        return;
    }

    else
    {
        idx = fseek(dat->file, (adresa-1)*sizeof(Baket), SEEK_SET);

        if (idx)
        {
            printf("\nGreska pri pretrazivanju baketa iz datoteke '%s'.\n", dat->ime);
            return;
        }

        else
        {
            idx = fread(baket, sizeof(Baket), 1, dat->file);

            if (idx != 1)
                printf("\nGreska pri citanju baketa iz datoteke '%s'.\n", dat->ime);
        }

    }
}
