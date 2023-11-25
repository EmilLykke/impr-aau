#include <stdio.h>
#include <math.h>
#include "functions.h"

int main(void)
{
  double p1_x, p1_y; /* Point 1's coordinates */
  double p2_x, p2_y; /* Point 2's coordinates */
  double p3_x, p3_y; /* Point 3's coordinates */
  double sum;
  
  /* Indlaes punkterne */
  printf("Giv mig tre punkter: \n");
  scanf(" %lf %lf %lf %lf %lf %lf", &p1_x, &p1_y, &p2_x, &p2_y, &p3_x, &p3_y);
  
  /* Udregn sum af sidelaengder */
  sum = sum_of_sides(p1_x, p1_y, p2_x, p2_y, p3_x, p3_y);

  /* Udskriv sum af sidelaengder */
  print_sum(sum);

  return 0;
}
