#include <stdio.h>

int main(void)
{
    int n, res = 0;
    printf("give n: ");
    scanf("%d", &n);
    if (n > 0)
    {
        for (int i = n; i < 2 * n; i++)
        {
            res += i;
        }
    }
    else if (n < 0)
    {
        for (int i = 2 * n; i > n; i--)
        {
            res -= i;
        }
    }
    printf("%d", res);

    return 0;
}