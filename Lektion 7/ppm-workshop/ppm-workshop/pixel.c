#include "pixel.h"

pixel make_pixel(unsigned int red, unsigned int green, unsigned int blue){
  return (1 << 24) | (red << 16) | (green << 8) | blue; 
}

unsigned int get_red(pixel p){
  return (p >> 16) & 0xff;
}

unsigned int get_green(pixel p){
  return (p >> 8) & 0xff;
}
unsigned int get_blue(pixel p){
  return p & 0xff;
}


