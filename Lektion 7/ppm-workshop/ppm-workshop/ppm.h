#include "pixel.h"

/* PPM IMAGES */

/* A new type that represents a PPM image */
typedef struct ppm{
   unsigned int width;
   unsigned int height;
   unsigned int **pixels;
   } ppm;

/* The constructor of a PPM image. Returns a pointer to a PPM image given the width,
   height and a background pixel (used throughout the entire image).  */
ppm *make_image(unsigned int width, unsigned int height, pixel background_pixel);

/* Set a single pixel in image at (x, y) to p.
   Drawing area: x in [0 .. width-1], y in [0 .. height-1].
   If (x,y) is outside the drawing area, the image is not affected. */
void set_pixel(ppm *image, unsigned int x, unsigned int y,  pixel p);

/* Return the pixel at position (x, y) in image.
   x and y must be within the drawing area:  x in [0 .. width-1], y in [0 .. height-1].*/
pixel get_pixel(ppm *image, unsigned int x, unsigned int y); 

/* Return the width of the image */
unsigned int image_width(ppm *img);

/* Return the height of the image */
unsigned int image_height(ppm *img);

/* Write the PPM image to a file named file_name.*/
void write_image(ppm *image, char *file_name);

/* Read an existing PPM image (P6) from a file named file_name and return it*/
ppm *read_image(char *file_name);

/* Release the resources of the PPM image */
void release_image(ppm *image);
