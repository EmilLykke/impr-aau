#include <stdio.h>

int main(void)
{
    int n, m, k, res = 0;
    while (1)
    {
        printf("Give me m, n, k\n");
        printf("m: ");
        scanf("%d", &m);

        printf("n: ");
        scanf("%d", &n);
        if (m > n)
        {
            printf("\nThe result is: 0\n\n");
            continue;
        }
        printf("k: ");
        scanf("%d", &k);
        if (k < 1)
        {
            while (k < 1)
            {
                printf("k needs to be bigger than 1\n");
                printf("k: ");
                scanf("%d", &k);
            }
        }

        for (int i = m; i <= n; i++)
        {
            if (i % k == 0)
                res += i;
        }
        printf("\nThe result is: %d\n\n", res);
    }
    return 0;
}