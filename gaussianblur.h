#ifndef PIXEL_OPERATIONS_H_
#define PIXEL_OPERATIONS_H_

#include <stdlib.h>
#include <SDL2/SDL.h>


double gauss_kernel_d3[];
void convolute(SDL_Surface* image_surface, double m[], size_t cols);

#endif

