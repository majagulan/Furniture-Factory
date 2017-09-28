#include "metode.h"

void formiranjePrazneDatoteke() {

    int i;
    Datoteka d;
    Baket bak;

    printf("\nUnesite naziv datoteke: ");
    fflush(stdin);
    gets(d.ime);

    d.file = fopen(d.ime, "wb");
    if (d.file != NULL)
    {
        //inicijalizacija slogova jednog baketa
        int i=0;
        while(i<b)  //zauzimqm b slogova u svakom baketu
        {
            bak.slog[i].evidencioni_broj = -1;

            int j=0;
            while(j < 70)
            {
                bak.slog[i].vrstaNamestaja[j] = ' ';
                j++;
            }

            bak.slog[i].dvp.dan = -1;
            bak.slog[i].dvp.mesec = -1;
            bak.slog[i].dvp.godina = -1;
            bak.slog[i].dvp.sati = -1;
            bak.slog[i].dvp.minuti = -1;

            int q=0;
            while(q < 50)
            {
                bak.slog[i].nazivModela[q] = ' ';
                q++;
            }

            bak.slog[i].tezina = -1;
            bak.slog[i].status = SLOBODAN;

            i++;
        }

        int w = 1;
        while(w <= B)       //baket u datoteku d upisujem
        {
            upisiBaket(&d, w, &bak);
            w++;
        }

        printf("\nDatoteka '%s' je uspesno formirana\n\n", d.ime);
    }

    else if(d.file == NULL)
        printf("\nOtvaranje datoteke '%s' nije uspelo\n", d.ime);


    if(fclose(d.file) == EOF)
        printf("Nastupila je greska tokom zatvaranja '%s' datoteke!\n", d.ime);
    else
        printf("Zatvaranje '%s' datoteke uspesno!\n", d.ime);
}
