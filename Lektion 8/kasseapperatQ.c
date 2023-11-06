#include <stdio.h>
#include <stdlib.h>

#define ANTAL_VARER 10

typedef struct
{
    int nr;
    double pris;
    float rabbat;
} Vare;

Vare *scan_array(int);
void print_array(Vare *, int);
int element_compare(const void *, const void *);

int main(void)
{
    int size;
    printf("Hvor mange vare: ");
    scanf(" %d", &size);

    Vare *kasse = scan_array(size);

    print_array(kasse, size);

    free(kasse);
    return 0;
}

void print_array(Vare *kasse, int length)
{
    double sum = 0;
    qsort(kasse, length, sizeof(Vare), element_compare);
    for (int i = 0; i < length; i++)
    {
        printf("Vare nr. %d koster: %lf kr.\n", kasse[i].nr, kasse[i].pris - (kasse[i].pris * kasse[i].rabbat));
        sum += kasse[i].pris - (kasse[i].pris * kasse[i].rabbat);
    }
    printf("Samlet pris af alle vare: %lf\n", sum);
}

Vare *scan_array(int length)
{
    Vare *kasse = (Vare *)malloc(length * sizeof(Vare));

    for (int i = 0; i < length; i++)
    {
        kasse[i].nr = i + 1;
        printf("Indtast pris for vare nr: %d:  ", i + 1);
        scanf(" %lf", &kasse[i].pris);

        printf("Ogsaa rabat (0-1): ");
        scanf(" %f", &kasse[i].rabbat);
    }
    return kasse;
}

int element_compare(const void *ip1, const void *ip2)
{
    int result;
    const Vare *ipi1, *ipi2;
    ipi1 = (Vare *)ip1;
    ipi2 = (Vare *)ip2;
    if (ipi1->pris < ipi2->pris)
        result = -1;
    else if (ipi1->pris > ipi2->pris)
        result = 1;
    else
        result = 0;
    return result;
}