#include <stdio.h>

int main(void)
{
    /*Part 1 vars*/
    double a = 22;
    double b = 7;

    /*Part 2 vars*/
    double celcius = 38.1;
    double salary = 38450.00;

    /* Part 1*/
    printf("%f, %f, %d, %d\n", a / b, b / a, (int)(a) % (int)(b), (int)(b) % (int)(a));

    a = 15;
    b = 16;
    printf("%f, %f, %d, %d\n", a / b, b / a, (int)(a) % (int)(b), (int)(b) % (int)(a));

    a = 3;
    b = 23;
    printf("%f, %f, %d, %d\n", a / b, b / a, (int)(a) % (int)(b), (int)(b) % (int)(a));

    a = -3;
    b = 16;
    printf("%f, %f, %d, %d\n", a / b, b / a, (int)(a) % (int)(b), (int)(b) % (int)(a));

    /* Part 2*/
    printf("%f\n", 1.8 * celcius + 32.0);

    printf("%f\n", (salary - 5000.00) * 0.20 + 1425.00);
    return 0;
}