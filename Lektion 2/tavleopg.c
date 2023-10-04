#include <stdio.h>
#include <math.h>

int main(void)
{
    double x1, y1, x2, y2, res;

    printf("Indtast x,y koordinat til punkt 1> ");
    scanf("%lf %lf", &x1, &y1);

    printf("Indtast x,y koordinat til punkt 2> ");
    scanf("%lf %lf", &x2, &y2);

    res = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));

    printf("\nAfstanden mellem punkterne er: %lf", res);
    return 0;
}
