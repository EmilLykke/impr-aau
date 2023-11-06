#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int element_compare(const void *, const void *);

int main(void)
{
    double *array = malloc(100 * sizeof(double));

    srand(time(NULL));

    for (int i = 0; i < 100; i++)
    {
        array[i] = 1 + rand() % 100;
    }

    printf("Foerste gang: \n");
    for (int i = 0; i < 100; i++)
    {
        printf("Numeber: %lf\n", array[i]);
    }

    qsort(array, 100, sizeof(double), element_compare);

    printf("Anden gang: \n");
    for (int i = 0; i < 100; i++)
    {
        printf("Numeber: %lf\n", array[i]);
    }

    free(array);

    return 0;
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
