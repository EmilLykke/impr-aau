/*

Name: Emil Lykke Grann
Email: egrann23@student.aau.dk
Education: Software (SW)
Assignment: Trapezoidal rule
Description:
Estimating the area under a graph using the trapezoidal rule

*/

#include <stdio.h>
#include <math.h>
#define A1 0
#define B1 3.14159
#define A2 -2
#define B2 2

double trap(double, double, int, double (*)());
double g(double);
double h(double);

int main(void)
{
    printf("This is the results for: x^2 * sin x\n");
    for (int i = 1; i < 8; i++)
    {
        printf("For n %lf, the result is: %lf\n", pow(2, i), trap(A1, B1, pow(2, i), g));
    }

    printf("\nThis is the results for: sqrt(4-x^2)\n");
    for (int i = 1; i < 8; i++)
    {
        printf("For n %lf, the result is: %lf\n", pow(2, i), trap(A2, B2, pow(2, i), h));
    }

    return 0;
}

double trap(double a, double b, int n, double (*f)())
{
    double h = (b - a) / n;
    double sum = 0;
    for (int i = 1; i < n - 1; i++)
    {
        sum += f(a + h * i);
    }

    double T = (h / 2) * (f(a) + f(b) + 2 * sum);
    return T;
}

double g(double x)
{
    return pow(x, 2) * sin(x);
}

double h(double x)
{
    return sqrt(4 - pow(x, 2));
}