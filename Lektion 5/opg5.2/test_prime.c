#include "primes.h"
#include <stdio.h>

int main(void)
{

    int i = 0, count = 0, nPrime = 0;
    printf("How many prime numbers would you like to find?: ");
    scanf("%d", &nPrime);

    while (count < nPrime)
    {
        if (is_prime(i))
        {
            printf("Prime %d: %d\n", count + 1, i);
            count++;
        }
        i++;
    }

    return 0;
}
