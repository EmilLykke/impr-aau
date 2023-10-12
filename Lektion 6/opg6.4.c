#include <stdio.h>

double half(double);
double multi_apply(double (*f)(double x), int, double);

int main(void)
{
    int n;
    double s, res;

    printf("Antal gange functionen skal kaldes og start value: ");
    scanf(" %d %lf", &n, &s);

    res = multi_apply(half, n, s);

    printf("Res is: %lf\n", res);

    return 0;
}

double half(double x)
{
    return x / 2;
}

double multi_apply(double (*f)(double x), int n, double s)
{
    for (int i = 0; i < n; i++)
    {
        s = f(s);
    }
    return s;
}