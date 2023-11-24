#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    char name[20];
    int kmt;
    int hk;
    int acc;
    int ccm;

} Bilkort;

void printCar(Bilkort);
Bilkort fastest(Bilkort, Bilkort);
Bilkort bilkortInput();
void gemIFil(Bilkort, FILE *);
void hentFraFil(FILE *, Bilkort *);

int main(void)
{

    Bilkort bil1 = {"Lotus", 200, 110, 8, 1973};
    Bilkort bil2 = {"Mercedes", 215, 160, 9, 4520};
    Bilkort bil3 = {"BMW", 300, 200, 9, 8341};
    // Bilkort bil1 = bilkortInput();
    // Bilkort bil2 = bilkortInput();
    Bilkort arr[] = {bil1, bil2, bil3};

    FILE *stream = fopen("bil-samling.txt", "w");

    if (stream == NULL)
    {
        printf("Failed to open file");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < 3; i++)
    {
        gemIFil(arr[i], stream);
    }
    fclose(stream);

    stream = fopen("bil-samling.txt", "r");

    Bilkort nyArr[3];

    hentFraFil(stream, nyArr);

    for (int i = 0; i < 3; i++)
    {
        printf("%s\n", nyArr[i].name);
    }

    fclose(stream);

    // printCar(bil1);
    // printf("\n");
    // printCar(bil2);
    // printf("\n");

    // printf("\nFastest car: \n");
    // printCar(fastest(bil1, bil2));
    return 0;
}

void printCar(Bilkort bil)
{
    printf("Navn: %s\n", bil.name);
    printf("Km/t: %d\n", bil.kmt);
    printf("HK: %d\n", bil.hk);
    printf("ACC: %d\n", bil.acc);
    printf("CCM: %d\n", bil.ccm);
}

Bilkort fastest(Bilkort bil1, Bilkort bil2)
{
    if (bil1.kmt < bil2.kmt)
    {
        return bil2;
    }
    return bil1;
}

Bilkort bilkortInput()
{
    Bilkort bil;
    printf("Name: ");
    scanf("%s", bil.name);

    printf("Kmt: ");
    scanf(" %d", &bil.kmt);

    printf("HK: ");
    scanf(" %d", &bil.hk);

    printf("ACC: ");
    scanf(" %d", &bil.acc);

    printf("CCM: ");
    scanf(" %d", &bil.ccm);

    return bil;
}

void gemIFil(Bilkort bil, FILE *stream)
{
    fprintf(stream, " %s %d %d %d %d\n", bil.name, bil.kmt, bil.hk, bil.acc, bil.ccm);
}

void hentFraFil(FILE *stream, Bilkort *arr)
{
    char line[1024];
    int i = 0;
    while (fgets(line, 1024, stream))
    {
        sscanf(line, " %s %d %d %d %d ", arr[i].name, &arr[i].kmt, &arr[i].hk, &arr[i].acc, &arr[i].ccm);
        i++;
    }
}