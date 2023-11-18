#include <stdio.h>
#include <float.h>

typedef struct
{
    char *name;
    double volumen;
    double massKg;
    double radius;
} Planet;

double masseFylde(Planet);

int main(void)
{
    // Planet planet1 = {
    //     "Jorden",
    //     1.08e12,
    //     5.97e24,
    //     6371};

    Planet planet1 = {
        "Jorden",
        0,
        5.97e24,
        6371};

    printf("Massefylde af %s: %.2lf kg/km^3\n", planet1.name, masseFylde(planet1) / 1e12);
    return 0;
}

double masseFylde(Planet p)
{
    return p.massKg / p.volumen;
}

double volumen(Planet p)
{
    return
}