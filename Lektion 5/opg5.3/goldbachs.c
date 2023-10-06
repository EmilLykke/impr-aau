#include "primes.h"
#include <stdio.h>

int main(void)
{
    int n, i = 0, j, prevPrime = 2, count;
    printf("Input the even number you want to check: ");
    scanf("%d", &n);
    while (count < 2000000)
    {
        if (is_prime(i))
        {
            for (j = 0; j < n; j++)
            {
                if (is_prime(j))
                {
                    if (j + i == n)
                    {
                        printf("The prime numbers which summs to %d is: %d %d\n", n, i, j);
                        return 0;
                    }
                }
            }

            count++;
        }
        i++;
    }

    return 0;
}