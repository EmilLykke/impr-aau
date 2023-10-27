#include <stdio.h>

int *arr()
{
    static int r[] = {1, 2, 3, 4};
    return r;
}

void add(int *arr)
{
    for (int i = 0; i < 10; i++)
    {
        arr[i] = i;
    }
}

int main(void)
{
    int *p;
    int q[10];

    p = arr();
    add(q);

    for (int i = 0; i < 10; i++)
    {
        printf("%d", q[i]);
    }

    return 0;
}