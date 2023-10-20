#include <stdio.h>

typedef enum haand
{
    rock,
    paper,
    scissor
} haand;

haand convert_haand(char);

int main(void)
{
    haand spiller1sHaand, spiller2sHaand;
    char input;
    int spiller1Vandt, spiller2Vandt;

    printf("Giv spiller1s haand (r for sten, s for saks, p for papir)\n");
    scanf(" %c", &input);
    spiller1sHaand = convert_haand(input);

    printf("Giv spiller2s haand (r for sten, s for saks, p for papir)\n");
    scanf(" %c", &input);
    spiller2sHaand = convert_haand(input);

    spiller1Vandt = (spiller1sHaand == rock && spiller2sHaand == scissor) || (spiller1sHaand == scissor && spiller2sHaand == paper) || (spiller1sHaand == paper && spiller2sHaand == rock);
    spiller2Vandt = (spiller2sHaand == rock && spiller1sHaand == scissor) || (spiller2sHaand == scissor && spiller1sHaand == paper) || (spiller2sHaand == paper && spiller1sHaand == rock);

    spiller1Vandt == spiller2Vandt ? printf("Uafgjort\n") : (spiller1Vandt ? printf("Spiller 1 vandt\n") : spiller2Vandt ? printf("Spiller 2 vandt\n")
                                                                                                                         : printf(" "));
    return 0;
}

haand convert_haand(char input)
{
    if (input != 'r' && input != 's' && input != 'p')
    {
        printf("Ugyldigt input");
        return 1;
    }
    else if (input == 'r')
    {
        return rock;
    }
    else if (input == 's')
    {
        return scissor;
    }
    else if (input == 'p')
    {
        return paper;
    }
}
