#include <stdio.h>
#include <float.h>
#include <math.h>
#include <stdlib.h>
#define _USE_MATH_DEFINES
#define ARR_LEN 2

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
void gemIFil(Planet, FILE *);
void hentPlaneterFraFil(FILE *, Planet *, int);

int main(void)
{

    Planet planet1 = {
        "Jorden",
        0,
        5.97e24,
        6371.0};
    Planet planet2 = {
        "Mars",
        0,
        6.39e23,
        3396.0};

    Planet planeter[ARR_LEN] = {planet1, planet2};

    FILE *stream = fopen("planeter.txt", "w");

    if (stream == NULL)
    {
        printf("Failed to open file");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < ARR_LEN; i++)
    {
        gemIFil(planeter[i], stream);
    }
    fclose(stream);

    stream = fopen("planeter.txt", "r");

    if (stream == NULL)
    {
        printf("Failed to open file");
        exit(EXIT_FAILURE);
    }

    Planet nyArr[ARR_LEN];

    hentPlaneterFraFil(stream, nyArr, ARR_LEN);

    for (int i = 0; i < ARR_LEN; i++)
    {
        printf("Volumen af %s: %.2e km^3\n", nyArr[i].name, nyArr[i].volumen);
    }

    fclose(stream);

    // planet1.volumen = volumen(planet1);
    // printf("Volumen af %s: %.2e km^3\n", planet1.name, planet1.volumen);

    // Planet planet2 = inputPlanet();
    // planet2.volumen = volumen(planet2);
    // printf("Volumen af %s: %.2e km^3\n", planet2.name, planet2.volumen);

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

void gemIFil(Planet p, FILE *stream)
{
    fprintf(stream, "%s %lf %e\n", p.name, p.radius, p.massKg);
}

void hentPlaneterFraFil(FILE *stream, Planet *p, int length)
{
    for (int i = 0; i < length; i++)
    {
        fscanf(stream, " %s %lf %lf", p[i].name, &p[i].radius, &p[i].massKg);
        p[i].volumen = volumen(p[i]);
    }
}