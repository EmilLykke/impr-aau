#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *udskift(char *, char, char);

int main(void)
{
    char str[] = "Foodback";
    printf("str: %s\n", str);
    char *newString = udskift(str, 'o', 'e');
    printf("str: %s\n", str);
    printf("newString: %s\n", newString);
    free(newString);

    return 0;
}

char *udskift(char *str, char oldChar, char newChar)
{
    char *newStr = (char *)malloc(strlen(str) + 1);
    if (newStr == NULL)
    {
        exit(EXIT_FAILURE);
    }
    strcpy(newStr, str);
    for (int i = 0; i < strlen(str); i++)
    {
        if (newStr[i] == oldChar)
        {
            newStr[i] = newChar;
        }
    }
    return newStr;
}
