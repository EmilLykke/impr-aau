#include "CuTest.h"
#include "functions.h"

void test_calc_side0010(CuTest *tc)
{
    double actual = calc_side(0, 0, 1, 0);
    double expected = 1;

    CuAssertDblEquals(tc, expected, actual, 0.01);
}

void test_calc_side0011(CuTest *tc)
{
    double actual = calc_side(0, 0, 1, 1);
    double expected = 1.414213;

    CuAssertDblEquals(tc, expected, actual, 0.01);
}

CuSuite *calc_sideGetSuite()
{
    CuSuite *suite = CuSuiteNew();
    SUITE_ADD_TEST(suite, test_calc_side0010);
    SUITE_ADD_TEST(suite, test_calc_side0011);

    return suite;
}

void test_sum_of_sides003034(CuTest *tc)
{
    double actual = sum_of_sides(0, 0, 3, 0, 3, 4);
    double expected = 12;

    CuAssertDblEquals(tc, expected, actual, 0.01);
}

CuSuite *sum_of_sidesGetSuite()
{
    CuSuite *suite = CuSuiteNew();
    SUITE_ADD_TEST(suite, test_sum_of_sides003034);

    return suite;
}