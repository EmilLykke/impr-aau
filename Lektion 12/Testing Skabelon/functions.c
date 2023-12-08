#include <stdio.h>
#include <math.h>
#include "CuTest.h"
#include "functions.h"

double sum_of_sides(double p1_x, double p1_y, double p2_x, double p2_y, double p3_x, double p3_y)
{
  double side1, side2, side3, sum;

  /* Calculate side 1 */
  side1 = calc_side(p1_x, p1_y, p2_x, p2_y);

  /* Calculate side 2 */
  // introducing fail here
  side2 = calc_side(p2_x, p2_y, p3_x, p3_y);

  /* Calculate side 3 */
  side3 = calc_side(p1_x, p1_y, p3_x, p3_y);

  /* Calculate sum */
  sum = side1 + side2 + side3;

  return sum;
}

double calc_side(double p1_x, double p1_y, double p2_x, double p2_y)
{
  double x_difference;
  double y_difference;
  double side;

  x_difference = p1_x - p2_x;
  y_difference = p1_y - p2_y;

  side = sqrt(x_difference * x_difference + y_difference * y_difference);

  return side;
}

void print_sum(double sum)
{
  printf("The sum is %f\n", sum);
}
