#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *flertal(char *);

int main(void)
{
    char navneord[][10] = {"chair",
                           "dairy",
                           "boss",
                           "circus",
                           "fly",
                           "dog",
                           "church",
                           "clue",
                           "dish"};
    for (int i = 0; i < 9; i++)
    {
        char *newFlertal = flertal(navneord[i]);
        printf("Ental: %s\n", navneord[i]);
        printf("Flertal: %s\n", newFlertal);
        free(newFlertal);
    }

    return 0;
}

char *flertal(char *str)
{
    char *newStr = (char *)malloc(strlen(str) + 4);
    if (newStr == NULL)
    {
        exit(EXIT_FAILURE);
    }
    strcpy(newStr, str);

    if (str[strlen(str) - 1] == 'y')
    {
        newStr[strlen(str) - 1] = 'i';
        newStr[strlen(str)] = 'e';
        newStr[strlen(str) + 1] = 's';
    }
    else if (str[strlen(str) - 1] == 's' || (str[strlen(str) - 2] == 'c' && str[strlen(str) - 1] == 'h') || (str[strlen(str) - 2] == 's' && str[strlen(str) - 1] == 'h'))
    {
        strcat(newStr, "es");
    }
    else
    {
        strcat(newStr, "s");
    }

    newStr[strlen(newStr) + 1] = '\0';
    return newStr;
}