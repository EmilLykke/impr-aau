#include <stdio.h>

void scale(double *gammel_b, double *gammel_l, double);

int main(void)
{
    double gammel_l, gammel_b, n;

    printf("Indtast laengde af plaene> ");
    scanf(" %lf", &gammel_l);

    printf("Indtast bredde af plaene> ");
    scanf(" %lf", &gammel_b);

    printf("Indtast faktor> ");
    scanf(" %lf", &n);

    scale(&gammel_b, &gammel_l, n);

    printf("Nye l: %lf, Nye b: %lf\n", gammel_l, gammel_b);

    return 0;
}

void scale(double *gammel_b, double *gammel_l, double n)
{
    *gammel_l = n * *gammel_l;
    *gammel_b = n * *gammel_b;
}