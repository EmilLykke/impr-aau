#include <stdio.h>

int main(void)
{
    int n, m, i, j;
    printf("Giv mig 2 numre:\n");
    printf("m: ");
    scanf("%d", &m);
    printf("n: ");
    scanf("%d", &n);
    for (j = 0; j < m; j++)
    {
        printf("%d", j + 1);

        for (i = 0; i < n; i++)
        {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}