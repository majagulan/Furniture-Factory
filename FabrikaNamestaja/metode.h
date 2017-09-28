#ifndef METODE_H
#define METODE_H

#include <string.h>
#include "strukture.h"

//FUNKCIONALNOSTI:

//1
void formiranjePrazneDatoteke();//
//2
void izborAktivneDatoteke(Datoteka* aktivna);//
//3
void prikazNazivaAktivneDatoteke(Datoteka* aktivna);//
//4
void upisNovogSlogaUDatoteku(Datoteka* aktivna);//
//5
void prikazSlogovaDatoteke(Datoteka* aktivna);//
//6
void logickoBrisanje(Datoteka* aktivna);//
//7
void ucitajSortirajPrikaziPoTezini(Datoteka *aktivna);

//DODATNE METODE:

int upisiBaket(const Datoteka* dat, unsigned int brojBaketa, Baket* baket);//
void nadjiBaket(Datoteka* aktivna, unsigned int adresa, Baket* baket);//
int daLiSlogPostoji(Datoteka* aktivna, int kljuc);//
void dodajISortirajListu (Komad komad);
void IspisiListu();
void IsprazniListu();


#endif // METODE_H
