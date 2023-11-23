#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_NAME_LGT 50

typedef struct
{
    char fornavn[MAX_NAME_LGT];
    char efternavn[MAX_NAME_LGT];
    char vejnavn[MAX_NAME_LGT];
    int vejnummer;
    int postnummer;
    char bynavn[MAX_NAME_LGT];
} person;

int sortEfter(const void *, const void *);

int main(void)
{

    FILE *stream = fopen("personer-ind.txt", "r");
    char line[1024];
    person persons[11];

    int i = 0;
    while (fgets(line, 1024, stream))
    {

        person temp;

        sscanf(line, " %s %[a-zA-Z] %*c %[^0123456789] %d%*c %d %[a-zA-Z]", temp.fornavn, temp.efternavn, temp.vejnavn, &temp.vejnummer, &temp.postnummer, temp.bynavn);
        persons[i] = temp;
        i++;
    }
    fclose(stream);

    for (int i = 0; i < 11; i++)
    {
        printf("Person name: %s\n", persons[i].efternavn);
    }

    qsort(persons, 11, sizeof(person), sortEfter);

    stream = fopen("sortedOurt.txt", "w");

    printf("\nSorted\n");
    for (int i = 0; i < 11; i++)
    {
        char line[130];
        sprintf(line, "%s: %s\n", persons[i].bynavn, persons[i].efternavn);
        printf("Person name: %s\n", persons[i].efternavn);
        fputs(line, stream);
    }

    return 0;
}

int sortEfter(const void *ip1, const void *ip2)
{

    person *ipi1, *ipi2;
    ipi1 = (person *)ip1;
    ipi2 = (person *)ip2;

    return strcmp(ipi1->efternavn, ipi2->efternavn);
    // if (ipi1->efternavn < ipi2->efternavn)
    // {
    //     /* code */
    // }
}