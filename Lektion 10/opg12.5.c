#include <stdio.h>

typedef struct
{
    unsigned int nummerator;
    unsigned int denummerator;

} frac;

void printBrok(frac);
unsigned int gcd(unsigned int, unsigned int);
frac forkort(frac);
frac multiplicer(frac, unsigned int);
frac multiFrac(frac, frac);
frac addFracs(frac, frac);

int main(void)
{
    frac brok1 = {3, 6};
    frac brok2 = {5, 10};

    printf("Brok 1:\n");
    printBrok(brok1);

    printf("Forkortet:\n");
    printBrok(forkort(brok1));

    int num = 5;
    printf("Ganget med %d:\n", num);
    printBrok(forkort(multiplicer(brok1, num)));

    printf("Brok1 og Brok2 ganget sammen:\n");
    printBrok(forkort(multiFrac(brok1, brok2)));

    printf("Brok1 og Brok2 plusset sammen:\n");
    printBrok(forkort(addFracs(brok1, brok2)));

    return 0;
}

void printBrok(frac brok)
{
    printf("%d\n", brok.nummerator);
    printf("--\n");
    printf("%d\n", brok.denummerator);
}
frac forkort(frac brok)
{
    unsigned int g = gcd(brok.nummerator, brok.denummerator);
    brok.nummerator /= g;
    brok.denummerator /= g;
    return brok;
}

frac multiplicer(frac brok, unsigned int num)
{
    brok.nummerator *= num;
    return brok;
}

frac multiFrac(frac brok1, frac brok2)
{
    frac total = {brok1.nummerator * brok2.nummerator, brok1.denummerator * brok2.denummerator};

    return total;
}

frac addFracs(frac brok1, frac brok2)
{
    unsigned int denumMulti = brok1.denummerator * brok2.denummerator;

    frac newBrok1 = {brok1.nummerator, brok1.denummerator * brok2.denummerator};
    frac newBrok2 = {brok2.nummerator, brok2.denummerator * brok1.denummerator};

    frac total = {newBrok1.nummerator + newBrok2.nummerator, newBrok1.denummerator};

    return total;
}

unsigned int gcd(unsigned int large, unsigned int small)
{
    unsigned int remainder;
    while (small > 0)
    {
        remainder = large % small;
        large = small;
        small = remainder;
    }
    return large;
}
