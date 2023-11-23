/*

Name: Emil Lykke Grann
Email: egrann23@student.aau.dk
Education: Software (SW)
Assignment: Spillekort
Description:
Et program det laver en array spillekort. Spillekortne
kan tage form som et normalt kort eller en joker.
Derefter scrambler den arrayen med spillekort og sortereden paa
baggrund af kulor og vaerdi

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef enum
{
    KULOR,
    VAERDI,
} vaerdiType;

typedef enum
{
    KLOR,
    RUDER,
    HJERTER,
    SPAR
} kulor;

typedef enum
{
    TO = 2,
    TRE,
    FIRE,
    FEM,
    SEKS,
    SYV,
    OTTE,
    NI,
    TI,
    KNAEGT,
    DAME,
    KONGE,
    ES,
    JOKER
} vaerdi;

typedef struct
{
    kulor kortKulor;
    vaerdi kortVaerdi;

} normaltkort;

typedef struct
{
    vaerdi kortVaerdi;

} joker;

typedef union
{
    normaltkort normKort;
    joker jokerKort;

} spillekort;

char *getStringVal(spillekort, vaerdiType);
void printKort(spillekort);
int rand_comparison(const void *, const void *);
int sortKort(const void *, const void *);
void sortOrShuffle(void *, size_t, size_t, int);

int main(void)
{
    srand(time(NULL));
    spillekort kortSpil[55];

    int size = 0;
    for (kulor i = KLOR; i <= SPAR; i++)
    {
        for (vaerdi j = TO; j < JOKER; j++)
        {
            kortSpil[size].normKort.kortKulor = i;
            kortSpil[size].normKort.kortVaerdi = j;
            size++;
        }
    }
    for (int i = 1; i <= 3; i++)
    {
        kortSpil[55 - i].jokerKort.kortVaerdi = JOKER;
    }

    sortOrShuffle(kortSpil, 55, sizeof(spillekort), 0);

    for (int i = 0; i < 55; i++)
    {
        printKort(kortSpil[i]);
    }
    printf("\n----------\n\n");
    sortOrShuffle(kortSpil, 55, sizeof(spillekort), 1);
    for (int i = 0; i < 55; i++)
    {
        printKort(kortSpil[i]);
    }

    return 0;
}

char *getStringVal(spillekort kort, vaerdiType type)
{
    if (kort.jokerKort.kortVaerdi == JOKER)
    {
        return "Joker";
    }
    else if (type == KULOR)
    {
        switch (kort.normKort.kortKulor)
        {
        case KLOR:
            return "Klor";
        case RUDER:
            return "Ruder";
        case HJERTER:
            return "Hjerter";
        case SPAR:
            return "Spar";
        default:
            break;
        }
    }
    else if (type == VAERDI)
    {
        switch (kort.normKort.kortVaerdi)
        {
        case TO:
            return "To";
        case TRE:
            return "Tre";
        case FIRE:
            return "Fire";
        case FEM:
            return "Fem";
        case SEKS:
            return "Seks";
        case SYV:
            return "Syv";
        case OTTE:
            return "Otte";
        case NI:
            return "Ni";
        case TI:
            return "Ti";
        case KNAEGT:
            return "Knaegt";
        case DAME:
            return "Dame";
        case KONGE:
            return "Konge";
        case ES:
            return "Es";

        default:
            break;
        }
    }
}

void printKort(spillekort kort)
{
    if (kort.jokerKort.kortVaerdi == JOKER)
    {
        printf("Kulor: ingen, vaerdi: %s\n", getStringVal(kort, VAERDI));
    }
    else
    {
        printf("Kulor: %s, vaerdi: %s\n", getStringVal(kort, KULOR), getStringVal(kort, VAERDI));
    }
}

void sortOrShuffle(void *base, size_t nmemb, size_t size, int op)
{
    if (op == 0)
    {
        qsort(base, nmemb, size, rand_comparison);
    }
    else
    {
        qsort(base, nmemb, size, sortKort);
    }
}

int sortKort(const void *ip1, const void *ip2)
{
    const spillekort *kort1 = (const spillekort *)ip1;
    const spillekort *kort2 = (const spillekort *)ip2;

    if (kort1->jokerKort.kortVaerdi != JOKER && kort2->jokerKort.kortVaerdi != JOKER)
    {
        if (kort1->normKort.kortKulor < kort2->normKort.kortKulor)
            return -1;
        if (kort1->normKort.kortKulor > kort2->normKort.kortKulor)
            return 1;
    }

    const vaerdi vaerdi1 = (kort1->jokerKort.kortVaerdi != JOKER) ? kort1->normKort.kortVaerdi : kort1->jokerKort.kortVaerdi;
    const vaerdi vaerdi2 = (kort2->jokerKort.kortVaerdi != JOKER) ? kort2->normKort.kortVaerdi : kort2->jokerKort.kortVaerdi;

    if (vaerdi1 < vaerdi2)
        return -1;
    if (vaerdi1 > vaerdi2)
        return 1;

    return 0;
}

int rand_comparison(const void *a, const void *b)
{

    return rand() % 2 ? +1 : -1;
}
