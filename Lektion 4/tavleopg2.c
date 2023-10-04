#include <stdio.h>

int main(void)
{
    int n, i, j;
    printf("Giv mig 1 numre:\n");
    printf("n: ");
    scanf("%d", &n);
    for (j = 0; j < n; j++)
    {
        printf("%d", j);

        for (i = 0; i < j; i++)
        {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}