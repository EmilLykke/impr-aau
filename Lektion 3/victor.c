#include <stdio.h>

// Sten, Saks, Papir-program der tager to input og beregner om spiller 1 har vundet
int main(void)
{
    char spiller1sHaand;
    char spiller2sHaand;
    int spiller1Vandt;
    int uafgjort;

    printf("Giv spiller1s hånd (r for sten, s for saks og p for papir)\n");

    // While-løkke, der kører indtil spiller2 har indtastet en gyldig værdi
    while (1)
    {
        scanf(" %c", &spiller1sHaand);
        if (spiller1sHaand == 'r' || spiller1sHaand == 's' || spiller1sHaand == 'p')
        {
            break; // Hop ud af løkken, når en gyldig værdi er blevet indtastet
        }
        else
        {
            printf("Ugyldig værdi. Prøv igen (Indtast r, s eller p): ");
        }
    }

    printf("Giv spiller2s hånd (r for sten, s for saks og p for papir)\n");

    // While-løkke, der kører indtil spiller2 har indtastet en gyldig værdi
    while (1)
    {
        scanf(" %c", &spiller2sHaand);
        if (spiller2sHaand == 'r' || spiller2sHaand == 's' || spiller2sHaand == 'p')
        {
            break; // Hop ud af løkken, når en gyldig værdi er blevet indtastet
        }
        else
        {
            printf("Ugyldigt valg. Prøv igen (r/s/p): ");
        }
    }

    spiller1Vandt = (spiller1sHaand == 'r' && spiller2sHaand == 's') ||
                    (spiller1sHaand == 's' && spiller2sHaand == 'p') ||
                    (spiller1sHaand == 'p' && spiller2sHaand == 'r');

    uafgjort = (spiller1sHaand == spiller2sHaand);

    if (uafgjort)
    {
        printf("Det blev uafgjort\n");
    }
    else if (spiller1Vandt)
    {
        printf("Spiller 1 vandt\n");
    }
    else
    {
        printf("Spiller 2 vandt\n");
    }

    return 0;
}