#include <stdio.h>
#include <math.h>
#define DELTA 0.005

int main(void)
{
    double r = 3, x, y, distance;

    printf("Input x and y, seperated by space, for coordinate: ");
    scanf("%lf %lf", &x, &y);

    distance = sqrt(pow(x, 2) + pow(y, 2));
    if (distance - r < DELTA && distance - r > -DELTA)
    {
        printf("The point is on the circle periphery");
    }
    else if (distance > r)
    {
        printf("The point is outside the circle");
    }
    else if (distance < r)
    {
        printf("The point is inside the circle");
    }
    return 0;
}
