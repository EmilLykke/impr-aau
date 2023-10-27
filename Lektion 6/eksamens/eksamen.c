/*

Name: Emil Lykke Grann
Email: egrann23@student.aau.dk
Education: Software (SW)
Assignment: Eksamens opgave 1
Description:
Calculater with different option. Both taking unary and binary operators.
The calculater is perfoming the action the the accumulator.
The final accumulator is printed when the user exits the program with 'q'.

*/

#include <stdio.h>
#include <math.h>

void scan_data(char *operator, double * operand, int *isUnary);
void do_next_op(char *operator, double * operand, double *accumulator, int *isUnary);
void run_calculator(double *accumulator);
void print_help();

int main(void)
{
    double accumulator = 0.0;
    run_calculator(&accumulator);

    printf("Final result is: %lf\n", accumulator);

    return 0;
}

void run_calculator(double *accumulator)
{
    char operator;
    double operand;
    int isUnary = 0;

    while (operator!= 'q')
    {
        scan_data(&operator, & operand, &isUnary);
        do_next_op(&operator, & operand, accumulator, &isUnary);
        printf("Result so far: %lf\n", *accumulator);
        isUnary = 0;
    }
}

//  Scans the data (operator, operand) from the user
void scan_data(char *operator, double * operand, int *isUnary)
{
    printf("Enter operator ('h' for help): ");
    scanf(" %c", operator);
    if (*operator== 'h')
    {
        print_help();
    }
    else if (*operator== '#' || * operator== '!' || * operator== '%' || * operator== 'q')
    {
        *isUnary = 1;
        *operand = 0.0;
    }
    else if (*operator== '+' || * operator== '-' || * operator== '*' || * operator== '/' || * operator== '^')
    {
        printf("Enter operand: ");
        scanf(" %lf", operand);
    }
    else
    {
        printf("Input was not an option, view 'h' for help.\n");
        printf("Try again.\n");
        scan_data(operator, operand, isUnary);
    }
}

// Does the next operation
void do_next_op(char *operator, double * operand, double *accumulator, int *isUnary)
{
    if (*isUnary)
    {
        switch (*operator)
        {
        case '#':
            // makes sure we do not take sqrt of negative number
            *accumulator = *accumulator < 0 ? *accumulator : sqrt(*accumulator);
            break;
        case '%':
            *accumulator *= -1;
            break;
        case '!':
            // makes sure we do not devide by 0
            *accumulator = *accumulator == 0 ? *accumulator : 1 / (*accumulator);
            break;
        default:
            break;
        }
    }
    else
    {
        switch (*operator)
        {
        case '+':
            *accumulator += *operand;
            break;
        case '-':
            *accumulator -= *operand;
            break;
        case '*':
            *accumulator *= *operand;
            break;
        case '/':
            *accumulator /= *operand;
            break;
        case '^':
            *accumulator = pow(*accumulator, *operand);
            break;
        default:
            break;
        }
    }
}

void print_help()
{
    printf("\nBinary operators to use:\n");
    printf("+    for addition of the accumulator with the operand for\n");
    printf("-    for subtraction of the accumulator with the operand\n");
    printf("*    for multiplication of the accumulator with the operand\n");
    printf("/    for division of the accumulator by the operand\n");
    printf("^    for raising the accumulator to the power of the operand\n");
    printf("-----------------------------\n");
    printf("Unary operators to use:\n");
    printf("#    for the square root of the accumulator\n");
    printf("%%   to change the sign of the accumulator\n");
    printf("!    to divide 1 by the accumulator\n");
    printf("q    to quit the calculator with the final result\n");
    printf("-----------------------------\n\n");
}