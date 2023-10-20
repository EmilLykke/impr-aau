#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef enum forret
{
    guacamole,
    tarteletter,
    lakserulle,
    graeskarsuppe

} forret;

typedef enum hovedret
{
    gyldenkaal,
    hakkeboef,
    gullash,
    forloren_hare
} hovedret;

typedef enum dessert
{

    pandekager_med_is,
    gulerodskage,
    choklademousse,
    citronfromag

} dessert;

void maaltid();
void print_fRet(forret);
void print_hRet(hovedret);
void print_dRet(dessert);

int main(void)
{
    srand(time(NULL));

    maaltid();

    return 0;
}

void maaltid()
{
    forret fRet;
    hovedret hRet;
    dessert dRet;

    for (int i = 0; i < 25; i++)
    {
        fRet = rand() % 4;
        hRet = rand() % 4;
        dRet = rand() % 4;

        printf("\nRet %d\n", i + 1);
        printf("Forret: ");
        print_fRet(fRet);

        printf("Hovedret: ");
        print_hRet(hRet);

        printf("Dessert: ");
        print_dRet(dRet);
        printf("\n");
    }
}

void print_fRet(forret f)
{
    switch (f)
    {
    case guacamole:
        printf("Guacamole\n");
        break;
    case tarteletter:
        printf("Tartletter\n");
        break;
    case lakserulle:
        printf("Lakserulle\n");
        break;
    case graeskarsuppe:
        printf("Graeskarsuppe\n");
        break;
    default:
        break;
    }
}

void print_hRet(hovedret h)
{
    switch (h)
    {
    case gyldenkaal:
        printf("Gyldenkaal\n");
        break;
    case hakkeboef:
        printf("Hakkeboef\n");
        break;
    case gullash:
        printf("Gullash\n");
        break;
    case forloren_hare:
        printf("Forloren hare\n");
        break;
    default:
        break;
    }
}

void print_dRet(dessert d)
{
    switch (d)
    {
    case pandekager_med_is:
        printf("Pandekager med is");
        break;
    case gulerodskage:
        printf("Gulerodskage");
        break;
    case choklademousse:
        printf("Choklademousse");
        break;
    case citronfromag:
        printf("Cistronfromag");
        break;
    default:
        break;
    }
}