#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *udskift(char *, char, char);
char *dub(char *);

int main(void)
{
    char str1[] = "Foodback";
    char str2[] = "Catback";

    char *str12 = (char *)malloc(strlen(str1) + strlen(str2) + 2);
    if (str12 == NULL)
    {
        exit(EXIT_FAILURE);
    }
    str12 = strcat(str1, str2);
    printf("%s\n", str12);

    return 0;
}