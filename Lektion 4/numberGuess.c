#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    int numberOfGuesses = 0, randomNumber, guess;
    srand(time(NULL));
    randomNumber = rand() % 20 + 1;
    do
    {
        printf("Skriv dit gaet: ");
        scanf("%d", &guess);
        if (guess < 0 || guess > 20)
        {
            printf("Dit gaet skal vaere mellem 0 og 20\n");
        }
        else if (guess < randomNumber)
        {
            printf("Tallet er stoerre.\n");
        }
        else if (guess > randomNumber)
        {
            printf("Tallet er mindre.\n");
        }
        numberOfGuesses++;
    } while (guess != randomNumber);

    printf("\nDu vandt! Du brugte %d forsoeg", numberOfGuesses);

    return 0;
}