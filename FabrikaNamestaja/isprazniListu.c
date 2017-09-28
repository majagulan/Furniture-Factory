#include "metode.h"

ElementListe* pocetak;

void isprazniListu()
{
    if (pocetak == NULL)
    {
        return;
    }

    else
    {
        int end = false;
        ElementListe* trenutni = pocetak;
        ElementListe* sledeci = trenutni->sledeci;

        if (sledeci != NULL)
        {
            do
            {
                free(trenutni);
                trenutni = sledeci;
                sledeci = trenutni->sledeci;

            } while (sledeci != NULL);
        }

        pocetak = NULL;
    }

}




