#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv)
{

    if (argc != 3)
    {
        printf("Ikke nok variabler\n");
        exit(EXIT_FAILURE);
    }

    char *word = argv[1];
    char *file = argv[2];

    FILE *stream = fopen(argv[2], "r");
    char line[1024];
    int lineNum = 0;
    while (fgets(line, 1024, stream) != NULL)
    {
        lineNum++;
        char *hej = strstr(line, word);
        if (hej)
        {
            printf("%s", hej);
            printf("%d\n", lineNum);
        }
    }
    fclose(stream);

    return 0;
}