#include <stdio.h>

struct linked
{
    int value;
    struct linked *tail;
};

typedef struct linked linked;

void printLinked(linked);
void summmm(linked, int *);
int main(void)
{
    linked bund = {8, NULL};
    linked middle = {15, &bund};
    linked start = {1, &middle};

    printLinked(start);
    int sum = 0;
    summmm(start, &sum);
    printf("sum: %d\n", sum);

    return 0;
}

void summmm(linked list, int *sum)
{
    *sum += list.value;
    if (list.tail != NULL)
    {
        summmm(*list.tail, sum);
    }
}

void printLinked(linked list)
{
    printf("%d ", list.value);
    if (list.tail != NULL)
    {
        printf("--> ");
        printLinked(*list.tail);
    }
    else
    {
        printf("\n");
    }
}