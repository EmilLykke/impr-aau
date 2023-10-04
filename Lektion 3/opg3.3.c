
#include <stdio.h>

int main(void)
{
    int ph;
    printf("Input pH: ");
    scanf("%d", &ph);
    if (ph <= 2)
        printf("Very acidic");
    else if (ph < 7)
        printf("Acidic");
    else if (ph == 7)
        printf("Neutral");
    else if (ph < 12)
        printf("Alkaline");
    else
        printf("Very alkaline");
    return 0;
}