#include <stdio.h>
#include <stdlib.h>

#define ANTAL_VARER 10

void scan_array(double *, float *, int);
void print_array(double *, float *, int);
int element_compare(const void *, const void *);

int main(void)
{
    double kasse[ANTAL_VARER];
    float rabat[ANTAL_VARER];
    scan_array(kasse, rabat, ANTAL_VARER);
    print_array(kasse, rabat, ANTAL_VARER);

    return 0;
}

void print_array(double *kasse, float *rabat, int length)
{
    double sum = 0;
    // qsort(kasse, length, sizeof(double), element_compare);
    for (int i = 0; i < length; i++)
    {
        printf("Vare nr. %d koster: %lf kr.\n", i + 1, kasse[i] - (kasse[i] * rabat[i]));
        sum += kasse[i] - (kasse[i] * rabat[i]);
    }
    printf("Samlet pris af alle vare: %lf\n", sum);
}

void scan_array(double *kasse, float *rabat, int length)
{
    for (int i = 0; i < length; i++)
    {
        printf("Indtast pris for vare nr: %d:  ", i + 1);
        scanf(" %lf", &kasse[i]);

        printf("Ogsaa rabat (0-1): ");
        scanf(" %f", &rabat[i]);
    }
}

int element_compare(const void *ip1, const void *ip2)
{
    int result;
    double *ipi1, *ipi2;
    ipi1 = (double *)ip1;
    ipi2 = (double *)ip2;
    if (*ipi1 < *ipi2)
        result = -1;
    else if (*ipi1 > *ipi2)
        result = 1;
    else
        result = 0;
    return result;
}