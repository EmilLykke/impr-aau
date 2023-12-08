#include "CuTest.h"

double sum_of_sides(double p1_x, double p1_y, double p2_x, double p2_y, double p3_x, double p3_y);
double calc_side(double p1_x, double p1_y, double p2_x, double p2_y);
void print_sum(double sum);
CuSuite *calc_sideGetSuite();
CuSuite *sum_of_sidesGetSuite();