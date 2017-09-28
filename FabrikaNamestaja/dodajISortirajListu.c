#include "metode.h"
#include <stdbool.h>

ElementListe* pocetak = NULL;


void dodajISortirajListu (Komad komad)
{
    ElementListe* element = (ElementListe*)malloc(sizeof(ElementListe));

    if(element == NULL) {
       printf("\nNeuspesno formiranje liste.\n");
      return;
    }

    element->komad.evidencioni_broj = komad.evidencioni_broj;
    strcpy(element->komad.vrstaNamestaja, komad.vrstaNamestaja);
    element->komad.dvp.dan = komad.dvp.dan;
    element->komad.dvp.mesec = komad.dvp.mesec;
    element->komad.dvp.godina = komad.dvp.godina;
    element->komad.dvp.sati = komad.dvp.sati;
    element->komad.dvp.minuti = komad.dvp.minuti;
    strcpy(element->komad.nazivModela, komad.nazivModela);
    element->komad.tezina = komad.tezina;

    element->sledeci = NULL;

    if (pocetak == NULL)
    {
        pocetak = element;
        return;
    }

    else
    {
        bool end = false;
        ElementListe* trenutni = pocetak;
        ElementListe* prethodni = NULL;

        do
        {
            if (trenutni->komad.tezina > komad.tezina)
            {
                element->sledeci = trenutni;

                if (prethodni != NULL)
                {
                    prethodni->sledeci = element;
                    end = true;
                }
                else
                {
                    pocetak = element;
                    end = true;
                }
            }

            else
            {
                if (trenutni->sledeci == NULL)
                {
                    trenutni->sledeci = element;
                    end = true;
                }
                else
                {
                    prethodni = trenutni;
                    trenutni = trenutni->sledeci;
                    end = false;
                }
            }

        } while (end == false);

    }

}

