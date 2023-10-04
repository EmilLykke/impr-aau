/*

Navn: Emil Lykke Grann
Email: egrann23@student.aau.dk
Studieretning: Software (SW)
Opgave: 4.6 Greatest common divisor (GCD)
Description:
Finds greatest common divisor between two numbers
using loops

*/

#include <stdio.h>

int main(void)
{

    int num1, num2, num1Largest, i;

    /*
    "Infinite" while loop which makes sure we can use the program
    multiple times before exiting. It will be infinite if you
    don't type in a negative number which breaks the loop
    */
    while (1)
    {
        printf("Type in you two numbers (a,b): ");
        scanf("%d %d", &num1, &num2);

        // if one of the numbers is negative, exit the program
        if (num1 < 0 || num2 < 0)
        {
            printf("\nProgram has been exited");
            break;
        }
        // if numbers are equal it is the GCD
        else if (num1 == num2)
        {
            printf("Greatest common devider is: %d\n\n", num1);
            continue;
        }
        // if one or both numbers numbers are equal to 0, use a special case
        else if (num1 == 0 || num2 == 0)
        {
            if (num1 == 0 && num2 != 0)
                printf("Greatest common devider is: %d\n\n", num2);
            else if (num1 != 0 && num2 == 0)
                printf("Greatest common devider is: %d\n\n", num1);
            else
                printf("Greatest common devider is: 0\n\n");
            continue;
        }

        // Link to info about ternary operators https://learn.microsoft.com/en-us/dotnet/csharp/language-reference/operators/conditional-operator
        num1Largest = num1 > num2;
        i = num1Largest ? num2 : num1;

        /*
        For loop which counts down from the smallest number.
        Prints the GCD
        */
        for (i; i > 0; i--)
        {
            if (num1 % i == 0 && num2 % i == 0)
            {
                printf("Greatest common devider is: %d\n\n", i);
                break;
            }
        }
    }
    return 0;
}