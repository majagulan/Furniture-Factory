#ifndef STRUKTURE_H
#define STRUKTURE_H

#include <stdio.h>

//ogranicenja
#define b 3 //VREDNOST_FAKTOR_BAKETIRANJA
#define B 7 //BROJ_BAKETA
#define k 3 //FIKSNI_KORAK

#define SLOBODAN 0 //za statusno polje u slogu
#define AKTIVAN 1

#define MAX_VRSTA_NAMESTAJA 70
#define MAX_NAZIV_MODELA 50
#define MAX_TEZINA 10000
#define MAX_NAZIV_DAT 30

#include <stdbool.h>

typedef struct {
    FILE *file;
    char ime[MAX_NAZIV_DAT];
    bool otvorena;
} Datoteka;

typedef struct {
    int dan;
    int mesec;
    int godina;
    int sati;
    int minuti;
} Datum_Vreme;

typedef struct slog {
    int evidencioni_broj; //9 cifara (kljuc)
    char vrstaNamestaja[MAX_VRSTA_NAMESTAJA];
    Datum_Vreme dvp;  //datum i vreme proizvodnje
    char nazivModela[MAX_NAZIV_MODELA];
    int tezina; //max 10000 kg
    int status; // 0 slobodna lokacija, 1 aktivan
} Komad;

typedef struct {
    Komad slog[b];  //svaki baket ima b slogova
} Baket;

typedef struct lista_komada ElementListe;

struct lista_komada
{
    Komad komad;
    ElementListe* sledeci;
};

#endif // STRUKTURE_H
