#include <stdio.h>
#include <math.h>

struct vektor
{
    int w1, w2;
};

struct vektor add(int u1, int u2, int v1, int v2)
{
    struct vektor res;
    res.w1 = u1 + v1;
    res.w2 = u2 + v2;
    return res;
}

struct vektor sub(int u1, int u2, int v1, int v2)
{
    struct vektor res;
    res.w1 = u1 - v1;
    res.w2 = u2 - v2;
    return res;
}

struct vektor multi(int u1, int u2, int scal)
{
    struct vektor res;
    res.w1 = u1 * scal;
    res.w2 = u2 * scal;
    return res;
}

int cross(int u1, int u2, int v1, int v2)
{
    int cr;
    cr = (u1 * v1) + (u2 * v2);
    return cr;
}

int leng(int u1, int u2)
{
    int res;
    res = sqrt(pow(u1, 2) + pow(u2, 2));
    return res;
}

int main(void)
{
    struct vektor result;
    int num;
    int u1, u2, v1, v2;

    printf("Give me x1, y1, x2, y2, separeted by space: ");
    scanf(" %d %d %d %d", &u1, &u2, &v1, &v2);

    result = add(u1, u2, v1, v2);
    printf("This is the sum of the vector: (%d, %d)\n", result.w1, result.w2);

    result = sub(u1, u2, v1, v2);
    printf("This is the sum of the vector: (%d, %d)\n", result.w1, result.w2);

    result = multi(u1, u2, 2);
    printf("This is the sum of the vector: (%d, %d)\n", result.w1, result.w2);

    num = cross(u1, u2, v1, v2);
    printf("This is the cross products: %d\n", num);

    num = leng(u1, u2);
    printf("This is the length of the first vector: %d\n", num);

    return 0;
}