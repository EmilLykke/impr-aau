#include <stdio.h>
#include <string.h>

int cum(char *, char *, int);
int main(void)
{
    if (cum("hei", "hej", 0))
    {
        printf("Du er ham\n");
    }
    return 0;
}

int cum(char *str1, char *str2, int index)
{
    if (index >= strlen(str1) || index >= strlen(str2))
    {
        return 1;
    }
    else if (str1[index] != str2[index])
    {
        return 0;
    }
    else
    {
        return cum(str1, str2, index + 1);
    }
}