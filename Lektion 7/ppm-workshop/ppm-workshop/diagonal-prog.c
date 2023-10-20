// Diagonal lines

#include <stdlib.h>
#include <stdio.h>
#include "ppm.h"

int main(void) {

  ppm *img = make_image(500, 500,  make_pixel(255U, 255U, 255U));  // white
  int i;

  pixel black_pixel = make_pixel(0U, 0U, 0U);

  for(i = 0; i < 500; i++){
    set_pixel(img, i, i, black_pixel);
    set_pixel(img, 500 - i - 1, i, black_pixel);
  }

  write_image(img, "img-diag.pnm");

  return 0;
}
