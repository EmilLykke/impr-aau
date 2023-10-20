#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "ppm.h"

/* IT IS NOT NECESSARY TO UNDERSTAND THE DETAILS OF THIS PROGRAM.  
   IT IS SUFFICIENT TO UNDERSTAND ppm.h  */

unsigned int **alloc_image(int m, int n){
  int i;
  unsigned int **dpp = (unsigned int **)malloc(m * sizeof(unsigned int *));
  if(dpp == NULL) {
    fprintf(stderr, "out of memory\n");
    exit(1);
  }
  for(i = 0; i < m; i++) {
    if((dpp[i] = (unsigned int *)malloc(n * sizeof(unsigned int))) == NULL) {
        fprintf(stderr, "out of memory\n");
        exit(1);
    }
  }
  return dpp;
}


void init_image(unsigned int **image, unsigned int width, unsigned int height,
                unsigned int red, unsigned int green, unsigned int blue){
  int x,y ;

  for(y = 0; y < height; y++)
    for (x = 0; x < width ; x++){
      image[x][y] = (red << 16) | (green << 8) | blue;
    }
}

ppm *make_image(unsigned int width, unsigned int height, pixel background_pixel){
  /* Allocate the struct: */
  ppm *the_image = malloc(sizeof(ppm));   

  /* Initialize the fields: */
  the_image->width = width;
  the_image->height = height;
  the_image->pixels = alloc_image(width,height);

  /* Initialize all pixels of image: */
  init_image(the_image->pixels, width, height, 
             get_red(background_pixel),
             get_green(background_pixel),
             get_blue(background_pixel));

  /* Return the pointer to the image: */
  return the_image;  
}

void set_pixel(ppm *image, unsigned int x, unsigned int y, pixel p){
  unsigned int **pixel_table = image->pixels;
  if (x >= 0 && x < image->width && y >= 0 && y < image->height)
     pixel_table[x][y] = (unsigned int)p;
}

pixel get_pixel(ppm *image, unsigned int x, unsigned int y){
  unsigned int **pixel_table = image->pixels;
  return (pixel)(pixel_table[x][y]);
}

/* Return the width of the image */
unsigned int image_width(ppm *img){
  return img->width;
}

/* Return the height of the image */
unsigned int image_height(ppm *img){
  return img->height;
}

void write_image(ppm *image, char *file_name){
  FILE *image_file;
  unsigned int **pixel_table = image->pixels;
  unsigned int r, g, b;
  int x, y;
  char width_height_str[50];

  image_file = fopen(file_name, "wb");  

  /* Write PPM header: */
  fputs("P6\n", image_file); 
  sprintf(width_height_str, "%d %d\n", image->width, image->height);
  fputs(width_height_str, image_file);
  fputs("255\n", image_file);

  /* Write pixels: */
  for(y = 0; y < image->height; y++)
    for (x = 0; x < image->width; x++){
         r = (pixel_table[x][y] >> 16) & 0xff;
         g = (pixel_table[x][y] >> 8) & 0xff;
         b = pixel_table[x][y] & 0xff;
         fputc(r, image_file);  fputc(g, image_file); fputc(b, image_file);
    }

  fclose(image_file);
}

int blank_char(int ch){
  return (ch == 32 || ch == 10 || ch == 12);
}

ppm *read_image(char *file_name){
  ppm *the_image = malloc(sizeof(ppm));     /* Allocate the ppm struct: */
  FILE *image_file;
  unsigned int **image;

  int ch, ch1, ch2, red, green, blue,
      width, height, pixel_depth,  x, y;

  image_file = fopen(file_name, "rb");  

  /* Get two first chars - expected 'P6': */
  ch1 = fgetc(image_file); ch2 = fgetc(image_file); 

  if (ch1 == 'P' && ch2 == '6'){
    fscanf(image_file, " %d", &width);  fscanf(image_file, " %d", &height);
    fscanf(image_file, " %d", &pixel_depth);

    if (pixel_depth == 255){
      the_image->width = width;
      the_image->height = height;
      the_image->pixels = alloc_image(width,height);      
      image = the_image->pixels;

      /* Read blank stuff before image: */
      while (blank_char(ch = fgetc(image_file))); 
      ungetc(ch, image_file);

      /* Read the image bytes */
      for(y = 0; y < height; y++)
        for (x = 0; x < width ; x++){
          red = fgetc(image_file); green = fgetc(image_file); blue = fgetc(image_file);
          image[x][y] = (red << 16) | (green << 8) | blue;
        }

      return the_image;
     }
     else {
       printf("Unsupported pixel depth. Bye.");
       exit(-1);
    }
  }
  else {
    printf("The image file does not seem to be PPM, P6 file. Bye.");
    exit(-1);
  }
}

void release_image(ppm *image){
  int i;
  for(i = 0; i <= image->width; i++)
    free(image->pixels[i]);
  free(image->pixels);
  image->pixels = NULL;
  image->width = 0;
  image->height = 0;
}
