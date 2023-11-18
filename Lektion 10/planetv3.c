#include <stdio.h>
#include <float.h>
#include <math.h>
#define _USE_MATH_DEFINES

typedef struct
{
    char name[20];
    double volumen;
    double massKg;
    double radius;
} Planet;

double masseFylde(Planet);
double volumen(Planet);
Planet inputPlanet();

int main(void)
{

    Planet planet1 = {
        "Jorden",
        0,
        5.97e24,
        6371};

    planet1.volumen = volumen(planet1);
    printf("Volumen af %s: %.2e km^3\n", planet1.name, planet1.volumen);

    Planet planet2 = inputPlanet();
    planet2.volumen = volumen(planet2);
    printf("Volumen af %s: %.2e km^3\n", planet2.name, planet2.volumen);

    return 0;
}

double masseFylde(Planet p)
{
    return p.massKg / p.volumen;
}

double volumen(Planet p)
{
    return (4.0 / 3.0) * pow(p.radius, 3) * M_PI;
}

Planet inputPlanet()
{
    Planet p;
    printf("Navn: ");
    scanf("%s", p.name);

    printf("Masse: ");
    scanf("%lf", &p.massKg);

    printf("Radius: ");
    scanf("%lf", &p.radius);
    return p;
}