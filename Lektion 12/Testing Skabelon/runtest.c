#include <stdio.h>
#include "CuTest.h"
#include "functions.h"

void RunAllTests(void);

int main(void)
{
    RunAllTests();
    return 0;
}

void RunAllTests(void)
{
    CuString *output = CuStringNew();
    CuSuite *suite = CuSuiteNew();

    // Adding test suites:
    CuSuiteAddSuite(suite, (CuSuite *)calc_sideGetSuite());
    CuSuiteAddSuite(suite, (CuSuite *)sum_of_sidesGetSuite());

    CuSuiteRun(suite);
    CuSuiteSummary(suite, output);
    CuSuiteDetails(suite, output);
    printf("%s\n", output->buffer);
}