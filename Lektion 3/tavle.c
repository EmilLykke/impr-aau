#include <stdio.h>

int main(void)
{
    char spiller1sHaand, spiller2sHaand;
    int spiller1Vandt, spiller2Vandt;

    printf("Giv spiller1s haand (r for sten, s for saks, p for papir)\n");
    scanf(" %c", &spiller1sHaand);

    if (spiller1sHaand != 'r' && spiller1sHaand != 's' && spiller1sHaand != 'p')
    {
        printf("Ugyldigt input");
        return 1;
    }

    printf("Giv spiller2s haand (r for sten, s for saks, p for papir)\n");
    scanf(" %c", &spiller2sHaand);

    if (spiller2sHaand != 'r' && spiller2sHaand != 's' && spiller2sHaand != 'p')
    {
        printf("Ugyldigt input");
        return 1;
    }

    spiller1Vandt = (spiller1sHaand == 'r' && spiller2sHaand == 's') || (spiller1sHaand == 's' && spiller2sHaand == 'p') || (spiller1sHaand == 'p' && spiller2sHaand == 'r');
    spiller2Vandt = (spiller2sHaand == 'r' && spiller1sHaand == 's') || (spiller2sHaand == 's' && spiller1sHaand == 'p') || (spiller2sHaand == 'p' && spiller1sHaand == 'r');

    spiller1Vandt == spiller2Vandt ? printf("Uafgjort") : (spiller1Vandt ? printf("Spiller 1 vandt") : spiller2Vandt ? printf("Spiller 2 vandt")
                                                                                                                     : printf(""));
    return 0;
}
