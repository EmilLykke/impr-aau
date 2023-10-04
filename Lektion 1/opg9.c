#include <stdio.h>

/*int main(void)
{
    float first_number, xxx, sidsteTal;

    printf("Give me three: ");
    scanf("%f%f%f", &first_number, &xxx, &sidsteTal);
    printf("The result: %f\n", (first_number + xxx + sidsteTal) / 3.0);
    return 0;
} */

int main(void)
{
    float num1, num2, num3;

    printf("Give me three nums:\n");
    printf("Num1: ");
    scanf("%f", &num1);
    printf("Num2: ");
    scanf("%f", &num2);
    printf("num3: ");
    scanf("%f", &num3);
    printf("The avarage is: %f\n", (num1 + num2 + num3) / 3.0);
    return 0;
}