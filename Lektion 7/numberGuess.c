#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    int rand1, rand2, rand3, guess = 0;
    srand(time(NULL));
    rand1 = rand() % 10 + 1;
    rand2 = rand() % 10 + 1;
    rand3 = rand() % 10 + 1;
    char nyt;
    do
    {
        printf("Skriv dit gaet: ");
        scanf("%d", &guess);
        if (guess == rand1 || guess == rand2 || guess == rand3)
        {
            nyt = 'n';
            printf("Du gaettede en af tallene: %d\n", guess);
            printf("Vil du starte et nyt spul? (y for ja): ");
            scanf(" %c", &nyt);
            if (nyt == 'y')
            {
                rand1 = rand() % 10 + 1;
                rand2 = rand() % 10 + 1;
                rand3 = rand() % 10 + 1;
                guess = 0;
            }
        }
    } while (guess != rand1 && guess != rand2 && guess != rand3);

    return 0;
}