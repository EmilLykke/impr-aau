#include <stdio.h>
/*
 * Computes the tax due based on a tax table.
 * Pre : salary is defined.
 * Post: Returns the tax due for 0.0 <= salary <= 150,000.00;
 * returns -1.0 if salary is outside the table range.
 */
double
comp_tax(double salary)
{
    double tax;

    if (salary < 0.0)
        tax = -1.0;
    else if (salary < 15000.00) /* first range */
        tax = 0.15 * salary;
    else if (salary < 30000.00) /* second range */
        tax = (salary - 15000.00) * 0.18 + 2250.00;
    else if (salary < 50000.00) /* third range */
        tax = (salary - 30000.00) * 0.22 + 5400.00;
    else if (salary < 80000.00) /* fourth range */
        tax = (salary - 50000.00) * 0.27 + 11000.00;
    else if (salary <= 150000.00) /* fifth range */
        tax = (salary - 80000.00) * 0.33 + 21600.00;
    else
        tax = -1.0;

    return (tax);
}

int main(void)
{

    double salary, tax;
    printf("Input your salary: ");
    scanf("%lf", &salary);
    tax = comp_tax(salary);
    printf("Your tax is: %lf", tax);
    return 0;
}