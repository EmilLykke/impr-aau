#include <stdio.h>
#include <math.h>

double afstand_mellem_punkter(double, double, double, double);
double regn_samlet_laengde(double, double, double, double, double, double);
void scanMan(double *p1_x, double *p1_y, double *p2_x, double *p2_y, double *p3_x, double *p3_y);

int main(void)
{
    double p1_x, p1_y, p2_x, p2_y, p3_x, p3_y;
    double samlet_sidelaengde;

    scanMan(&p1_x, &p1_y, &p2_x, &p2_y, &p3_x, &p3_y);

    samlet_sidelaengde = regn_samlet_laengde(p1_x, p1_y, p2_x, p2_y, p3_x, p3_y);
    printf("Samlet sidelængde: %lf\n", samlet_sidelaengde);

    return 0;
}

double afstand_mellem_punkter(double x1, double y1, double x2, double y2)
{
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

double regn_samlet_laengde(double x1, double y1, double x2, double y2, double x3, double y3)
{
    double side1, side2, side3;
    side1 = afstand_mellem_punkter(x1, y1, x2, y2);
    side2 = afstand_mellem_punkter(x2, y2, x3, y3);
    side3 = afstand_mellem_punkter(x3, y3, x1, y1);
    return side1 + side2 + side3;
}

void scanMan(double *p1_x, double *p1_y, double *p2_x, double *p2_y, double *p3_x, double *p3_y)
{
    printf("Indtast punkterne:\n");
    scanf(" %lf %lf %lf %lf %lf %lf", p1_x, p1_y, p2_x, p2_y, p3_x, p3_y);
}