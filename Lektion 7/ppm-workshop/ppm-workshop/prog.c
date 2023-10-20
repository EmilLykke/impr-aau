#include <stdlib.h>
#include <stdio.h>
#include "ppm.h"

int main(void) {

  ppm *img = make_image(500, 500, make_pixel(255U, 0U, 0U));

  write_image(img, "img1.pnm");

  release_image(img);

  return 0;
}
