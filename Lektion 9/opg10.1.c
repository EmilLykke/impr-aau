#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *rev(char *);

int main(void)
{
    char str[] = "hej";

    char *newWord = rev(str);
    printf("org: %s\n", str);
    printf("rev: %s\n", newWord);
    free(newWord);

    return 0;
}

char *rev(char *str)
{
    char *new = (char *)malloc(strlen(str) + 1);
    for (int i = 0; i < strlen(str); i++)
    {
        new[i] = str[strlen(str) - (i + 1)];
    }
    return new;
}
