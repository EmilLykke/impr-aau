#include <stdio.h>

int main(void)
{
    int n, i, j;
    printf("Giv mig 1 nummer:\n");
    printf("n: ");
    scanf("%d", &n);
    for (j = 0; j < n; j++)
    {
        printf("%d", j);

        for (i = 0; i < n; i++)
        {
            if (n - j <= i)
                printf("*");
            else
                printf(" ");
        }

        printf("\n");
    }
    return 0;
}