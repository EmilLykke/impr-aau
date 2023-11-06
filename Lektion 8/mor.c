#include <stdio.h>
#include <stdlib.h>

int *init(int, int);

int main(void)
{
    int length, n;

    printf("Give me length: ");
    scanf(" %d", &length);

    printf("Give me n: ");
    scanf(" %d", &n);

    int *arr = init(length, n);

    for (int i = 0; i < length; i++)
    {
        printf("nr: %d, %d\n", i + 1, arr[i]);
    }

    free(arr);

    return 0;
}

int *init(int length, int n)
{
    int *arr = (int *)malloc(length * sizeof(int));
    if (arr == NULL)
    {
        print("Fejl");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < length; i++)
    {
        arr[i] = n;
    }

    return arr;
}