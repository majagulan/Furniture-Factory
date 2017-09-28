#include "metode.h"
#include "math.h"

unsigned int transformacijaKljuca(int kljuc)
{
    unsigned long int kk = pow(kljuc, 2);
    unsigned int Q = B;      //broj baketa rasute datoteke
    unsigned int v = 10;  //osnova dekadnog sistema
    unsigned int p = 9;     // maksimalni broj cifara vrednosti kljuca (evidencionog broja) - zadato je 9

    unsigned int n = ceil(log10((double)Q));    //broj pozicija relativne adrese
    unsigned int t = floor((double)p - (double)n/2.0);      //pozicija najlakse cifre podniza

    // r - relativna adresa maticnog baketa
    unsigned int r = (int)floor(kk / pow((double)v,(double)t)) % (int)floor(pow((double)v,(double)n));
    r = floor( ((r*Q) / pow((double)v,(double)n)) ) + 1;
    printf("**************transformacijom se dobio baket sa rednim brojem: %d\n", r);

    return r;
}

