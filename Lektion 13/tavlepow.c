#include <stdio.h>

int power(int, int);

int main(void)
{
    int x, y;
    printf("Giv mig to tal: ");
    scanf("%d %d", &x, &y);

    printf("%d ^ %d = %d\n", x, y, power(x, y));
    return 0;
}

int kvadrer(int x)
{
    return x * x;
}

int power(int tal, int potens)
{
    if (potens == 0)
    {
        return 1;
    }
    else if (potens % 2 == 0)
    {
        return kvadrer(power(tal, potens / 2));
    }
    else
    {
        return tal * power(tal, potens - 1);
    }
}
