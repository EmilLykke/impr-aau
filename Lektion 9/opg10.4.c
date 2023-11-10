#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *suf(char *, char *);

int main(void)
{
    char str1[10], str2[10], *suff;
    printf("Ord 1: ");
    scanf("%s", str1);

    printf("Ord 2: ");
    scanf("%s", str2);

    suff = suf(str1, str2);

    printf("Dette er suffix: %s\n", suff);

    return 0;
}

char *suf(char *str1, char *str2)
{
    int length = strlen(str1) > strlen(str2) ? strlen(str1) : strlen(str2);
    int i;
    char *suffix;
    for (i = 0; i < length; i++)
    {
        if (str1[strlen(str1) - (i + 1)] != str2[strlen(str2) - (i + 1)])
        {
            suffix = &str1[strlen(str1) - (i)];
            break;
        }
        else
        {
            suffix = str1;
        }
    }
    return suffix;
}
