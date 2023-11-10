#include <stdio.h>
#include <string.h>

void udskift(char *, char, char);

int main(void)
{
    char str[] = "Foodback";
    printf("%s\n", str);
    udskift(str, 'o', 'e');
    printf("%s\n", str);

    return 0;
}

void udskift(char *str, char oldChar, char newChar)
{
    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] == oldChar)
        {
            str[i] = newChar;
        }
    }
}
