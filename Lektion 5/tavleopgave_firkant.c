#include <stdio.h>
#include <math.h>

double afstand_mellem_punkter(double, double, double, double);
double regn_samlet_laengde(double, double, double, double, double, double, double, double);

int main(void)
{
    double p1_x, p1_y, p2_x, p2_y, p3_x, p3_y, p4_x, p4_y;
    double samlet_sidelaengde;
    printf("Indtast punkterne:\n");
    scanf(" %lf %lf %lf %lf %lf %lf %lf %lf", &p1_x, &p1_y, &p2_x, &p2_y, &p3_x, &p3_y, &p4_x, &p4_y);

    samlet_sidelaengde = regn_samlet_laengde(p1_x, p1_y, p2_x, p2_y, p3_x, p3_y, p4_x, p4_y);
    printf("%lf", samlet_sidelaengde);

    return 0;
}

double afstand_mellem_punkter(double x1, double y1, double x2, double y2)
{
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

double regn_samlet_laengde(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4)
{
    double side1, side2, side3, side4;
    side1 = afstand_mellem_punkter(x1, y1, x2, y2);
    side2 = afstand_mellem_punkter(x2, y2, x3, y3);
    side3 = afstand_mellem_punkter(x3, y3, x4, y4);
    side4 = afstand_mellem_punkter(x4, y4, x1, y1);
    return side1 + side2 + side3 + side4;
}