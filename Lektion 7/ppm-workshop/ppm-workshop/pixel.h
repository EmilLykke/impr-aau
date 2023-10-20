/* PIXELS - A pixel represents a RGB color. */

/** A new type that represents a single RGB pixel */
typedef unsigned int pixel;

/** The constructor of a pixel in terms of red, green and blue (between 0 and 255) */
pixel make_pixel(unsigned int red, unsigned int green, unsigned int blue);

/** Access and return the red component of the pixel p */
unsigned int get_red(pixel p);

/** Access and return the green component of the pixel p */
unsigned int get_green(pixel p);

/** Access and return the blue component of the pixel p */
unsigned int get_blue(pixel p);



