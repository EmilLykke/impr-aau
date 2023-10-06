#include <stdio.h>

#define _USE_MATH_DEFINES
#include <math.h>

double regn_omkreds(double);
double regn_areal(double);

int main(void)
{
    char valg;
    double radius;

    printf("Indtast radius: ");
    scanf("%lf", &radius);

    printf("Beregn Areal (a) eller Omkreds (o) af cirkel: ");
    scanf(" %c", &valg);

    if (valg == 'a')
    {
        printf("Areal er: %.2lf", regn_areal(radius));
    }
    else if (valg == 'o')
    {
        printf("Omkreds er: %.2lf", regn_omkreds(radius));
    }
    else
    {
        printf("Dit valg var ikke muligt :(");
    }

    return 0;
}

double regn_omkreds(double r)
{
    return 2 * M_PI * r;
}

double regn_areal(double r)
{
    return M_PI * pow(r, 2);
}