#include <stdio.h>
#include <string.h>
#include <ctype.h>

void ersmaat(char *);
char *firstlower(char *);

int main(void)
{
    char str[] = "Foodback";
    printf("%s\n", str);
    ersmaat(str);
    char *first = firstlower(str);
    printf("%c\n", *first);

    return 0;
}

void ersmaat(char *str)
{
    int antal = 0;
    for (int i = 0; i < strlen(str); i++)
    {
        if (islower(str[i]))
        {
            antal++;
        }
    }
    printf("%d\n", antal);
}

char *firstlower(char *str)
{
    for (int i = 0; i < strlen(str); i++)
    {
        if (islower(str[i]))
        {
            return &str[i];
        }
    }
}
