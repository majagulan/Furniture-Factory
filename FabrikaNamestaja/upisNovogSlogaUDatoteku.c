#include "strukture.h"

void upisNovogSlogaUDatoteku(Datoteka* aktivna) {

    Komad komad;
    int trenutniBaket, maticniBaket = 0;
    Baket baket;
    int adresa = 0;

    if(!aktivna->otvorena)
    {
        printf("\nNe postoji aktivna datoteka.\n");
        return;
    }

    printf("\n\tUnos komada:");
    komad.status = AKTIVAN;

    //UNOS PODATAKA

    //evidencioni broj
    int test1 = 0;
    while (test1 == 0)
    {
        printf("\n\nUnesite evidencioni broj (tacno 9 cifara):");
        fflush(stdin);
        scanf("%d", &komad.evidencioni_broj);

        if (komad.evidencioni_broj>999999999)
            printf("\n\nGreska, evidencioni broj mora imati 9 cifara.\n");
        else if (komad.evidencioni_broj<100000000)
            printf("\n\nGreska, evidencioni broj mora imati 9 cifara.\n");
        else
            test1 = 1;
    }

    if (daLiSlogPostoji(aktivna, komad.evidencioni_broj))
    {
        printf("\n\nEvidencioni broj '%d' vec postoji.\n", komad.evidencioni_broj);
        return;
    }

    //vrsta namestaja
    int test2 = 0;
    while (test2 == 0)
    {
        printf("\n\nUnesite vrstu namestaja (max. 32 karaktera):");
        fflush(stdin);
        gets(komad.vrstaNamestaja);
        if (strlen(komad.vrstaNamestaja) > MAX_VRSTA_NAMESTAJA)
            printf("\n\nVrsta namestaja moze imati najvise 70 karaktera.\n");
        else
           test2 = 1;
    }

    //unos datuma i vremena
    printf("\n\nUnos datuma i vremena...\n");

    int test3 = 0;
    while (test3 == 0)
    {
        printf("\nDan:");
        fflush(stdin);
        scanf("%d", &komad.dvp.dan);
        if (komad.dvp.dan > 31 || komad.dvp.dan < 1)
            printf("\nDan mora imati vrednost od 1-31.\n");
        else
            test3 = 1;
    }

    int test4 = 0;
    while (test4 == 0)
    {
        printf("\nMesec:");
        fflush(stdin);
        scanf("%d", &komad.dvp.mesec);
        if (komad.dvp.mesec>12 || komad.dvp.mesec<1)
            printf("\nMesec mora imati vrednost od 1-12.\n");
        else
            test4 = 1;
    }

    int test5 = 0;
    while (test5 == 0)
    {
        printf("\nGodina:");
        fflush(stdin);
        scanf("%d", &komad.dvp.godina);
        if (komad.dvp.godina > 2017 || komad.dvp.godina < 1900)
            printf("\nGodina mora imati vrednost od 1900-2017.\n");
        else
            test5 = 1;
    }

    int test6 = 0;
    while (test6 == 0)
    {
        printf("\nSati:");
        fflush(stdin);
        scanf("%d", &komad.dvp.sati);
        if (komad.dvp.sati > 24 || komad.dvp.dan < 0)
            printf("\nSat mora imati vrednost od 0-24.\n");
        else
            test6 = 1;
    }

    int test7 = 0;
    while (test7 == 0)
    {
        printf("\nMinuti:");
        fflush(stdin);
        scanf("%d", &komad.dvp.minuti);
        if (komad.dvp.minuti > 60 || komad.dvp.dan < 0)
            printf("\nMinut mora imati vrednost od 0-60.\n");
        else
            test7 = 1;
    }

    //unos naziva modela
    int test8 = 0;
    while (test8 == 0)
    {
        printf("\nUnesite naziv modela (max. 50 karaktera):");
        fflush(stdin);
        gets(komad.nazivModela);
        if (strlen(komad.nazivModela) > MAX_NAZIV_MODELA)
            printf("\nOpis naziva modela moze imati najvise 50 karaktera.");
        else
            test8 = 1;
    }

    //unos tezine
    int test9 = 0;
    while (test9 == 0)
    {
        printf("\nUnesite tezinu (max. 10 000 kg):");
        fflush(stdin);
        scanf("%d", &komad.tezina);
        if (komad.tezina > 10000 || komad.tezina < 1)
            printf("\nZeljena tezina moze imati maksimalno 10 000 kg, a minimalno 1 kg.\n");
        else
            test9 = 1;
    }

    printf("\n\n-------Sacuvani uneti podaci!-------");


    //sve je sacuvano u komadu, upisujemo slog u datoteku

    //generisanje adrese maticnog baketa
    trenutniBaket = transformacijaKljuca(komad.evidencioni_broj);
    maticniBaket = trenutniBaket;

    int lokacija = 0;

    int upisan = 0;

    do{
        //nadji i ucitaj baket na trenutnoj adresi
        nadjiBaket(aktivna, trenutniBaket, &baket);

        while (lokacija < b)    //procicemo kroz sve slogove baketa
        {
            if(baket.slog[lokacija].status == SLOBODAN) //da li je lokacija sloga slobodna
            {
                baket.slog[lokacija] = komad;
                if (upisiBaket(aktivna, trenutniBaket, &baket) == 1)
                {
                    printf("\nNovi slog je uspesno upisan na adresu baketa: %d\n", trenutniBaket);
                    printf("\nRedni broj sloga u baketu je: %d\n", lokacija+1);
                    if (trenutniBaket != maticniBaket)
                        printf("\nSlog je prekoracio iz maticnog baketa %d u baket %d\n\n", maticniBaket, trenutniBaket);
                 }
                 else
                    printf("\nSlog nije uspesno upisan.\n");
                upisan = 1;
                break;
            }
            lokacija++;
        }

        if(upisan == 0)
        {
            trenutniBaket = trenutniBaket + k;
            if (trenutniBaket > B)
                trenutniBaket = trenutniBaket % B;
        }

    } while(upisan == 0 && trenutniBaket != maticniBaket);

}
