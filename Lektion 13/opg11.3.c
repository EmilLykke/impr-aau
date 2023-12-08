#include <stdio.h>

int quotient(int, int);
int modulus(int, int);

int main(void)
{
    int x, y;
    printf("Indtast tal: \n");
    scanf("%d %d", &x, &y);

    int antal = quotient(x, y);
    int rest = modulus(x, y);
    printf("Antal: %d rest %d", antal, rest);
    return 0;
}

int quotient(int dividend, int divisor)
{
    int num = dividend - divisor;
    if (divisor == 0)
    {
        printf("canont devide by zero");
        return 0;
    }
    else if (dividend < divisor)
    {
        return 0;
    }
    else
    {

        return quotient(num, divisor) + 1;
    }
}

int modulus(int dividend, int divisor)
{
    if (dividend < divisor)
    {
        return dividend;
    }
    else
    {
        return modulus(dividend - divisor, divisor);
    }
}