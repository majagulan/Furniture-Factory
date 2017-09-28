#include "metode.h"

//return 1 - uspesno upisivanje,
//return 0 - greska pri upisu

int upisiBaket(const Datoteka* dat, unsigned int brojBaketa, Baket* baket) {

	int inx;

	if(brojBaketa < 1 || brojBaketa > B)
	{
		printf("\nNeispravan broj baketa\n");
		return 0;
	}

	else
	{
        inx = fseek(dat->file, (brojBaketa-1)*sizeof(Baket), SEEK_SET);

        if(inx != 0)
        {
            printf("\nGreska pri pretrazivanju datoteke '%s'\n", dat->ime);
            return 0;
        }

        else
        {
            inx = fwrite(baket, sizeof(Baket), 1, dat->file);

            if(inx != 1)
            {
                printf("\nGreska pri upisu baketa u datoteku '%s'\n", dat->ime);
                return 0;
            }
            else
                return 1;
        }

	}
}
