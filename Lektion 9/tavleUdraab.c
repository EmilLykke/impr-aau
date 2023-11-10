#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *udskift(char *, char, char);
char *dub(char *);

int main(void)
{
    char str[] = "Foodback";
    printf("str: %s\n", str);
    char *newString = udskift(str, 'o', 'e');
    printf("newString: %s\n", newString);
    free(newString);

    char *newDubString = dub(str);
    printf("newDub: %s\n", newDubString);
    free(newDubString);

    return 0;
}

char *udskift(char *str, char oldChar, char newChar)
{
    char *newStr = (char *)malloc(strlen(str) + 2);
    if (newStr == NULL)
    {
        exit(EXIT_FAILURE);
    }
    strcpy(newStr, str);
    newStr[strlen(newStr)] = '!';
    newStr[strlen(newStr) + 1] = '\0';
    return newStr;
}

char *dub(char *str)
{

    char *newStr = (char *)malloc(strlen(str) * 2 + 1);
    if (newStr == NULL)
    {
        exit(EXIT_FAILURE);
    }
    strcpy(newStr, str);
    int j = 0;
    for (int i = 0; i < strlen(str); i++)
    {
        newStr[j] = str[i];
        j++;
        newStr[j] = str[i];
        j++;
    }
    newStr[strlen(newStr) + 1] = '\0';
    return newStr;
}