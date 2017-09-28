#include "metode.h"

int menu() {
    int unos;
    fflush(stdin);

    printf("\n1 - Formiranje prazne datoteke i zadavanje naziva \n");
    printf("2 - Izbor aktivne datoteke zadavanjem njenog naziva \n");
    printf("3 - Prikaz naziva aktivne datoteke \n");\
    printf("4 - Upis novog sloga u aktivnu datoteku \n");
    printf("5 - Prikaz svih slogova aktivne datoteke zajedno sa adresom baketa i rednim brojem sloga u baketu \n");
    printf("6 - Logicko brisanje svih aktuelnih slogova iz aktivne datoteke \n");
    printf("7 - Ucitavanje slogova u dinamicku strukturu po zadatoj tezini \n");
    printf("8 - Kraj \n\n");
    printf("\nUnesite broj od 1 do 8: ");
    scanf("%d", &unos);
    return unos;
}
