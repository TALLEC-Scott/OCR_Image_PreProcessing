#ifndef GAUSSIAN_BLUR_H_
#define GAUSSIAN_BLUR_H_

#include <stdlib.h>
#include <SDL/SDL.h>


double gauss_kernel_d3[9];
void convolute(SDL_Surface* image_surface, double m[], size_t cols);

#endif

