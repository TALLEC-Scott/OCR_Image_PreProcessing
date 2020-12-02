#include<SDL/SDL.h>
#include<SDL/SDL_image.h>
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<err.h>
#include<math.h>
#include "pixeloperations.h"

//need to implement the linear structure for matrices
// double m[], size_t rows, size_t cols


//program to generate Gaussian filter
double gauss_kernel_d3[9] =    // guauss kernel dim 3 (approximation), calculated ahead of time
{
    1./16, 1./8, 1./16,
    
    1./8, 1./4, 1./8,
    
    1./16, 1./8, 1./16
}

/*

double[] FilterCreation()
{
    double sigma = 1.0; //here we do it for signma =1
    double r,s = 2.0 * sigma * sigma;

    double sum = 0.0;
    
    double GKernel[3][3] = {{0}};

for (int x = -1; x <= 1; x++) { 
        for (int y = -1; y <= 1; y++) { 
            r = sqrt(x * x + y * y); 
            GKernel[x + 1][y + 1] = (exp(-(r * r) / s)) / (M_PI * s); 
            sum += GKernel[x + 1][y + 1]; 
        } 
    } 

    // normalising the Kernel 
    for (int i = 0; i < 3; ++i) 
        for (int j = 0; j < 3; ++j) 
            GKernel[i][j] /= sum; 


return GKernel;
}
*/

// for edge cases we will ignore, though there are different solutions to this problem, it's unlikely that the letters will be
// on the edge of the image.

// The Gaussian smoothing can be performed using standard convolution methods

void convolute(SDL_Surface* image_surface, double m[], size_t cols){  //intended for grayscaled image and kernel of dim 3

    int width = image_surface->w;
    int height = image_surface->h;
    double sum;
    Uint8 r1, g1, b1;
    Uint32 pixel;
    SDL_Surface* image_surface_copy;
    SDL_BlitSurface(image_surface, NULL, image_surface_copy,NULL)
    
    
    for (size_t i = 1; i < height-1; i++)
    {
        for (size_t j = 1; j < width-1; j++)
        {
            sum = 0;
            for (size_t x = -1; i <= 1; x++)
            {
                for (size_t y = -1; i <= 1; y++)
                {
                    pixel = get_pixel(image_surface_copy,j+y,x+i);
                    DL_GetRGB(pixel, image_surface_copy->format, &r1, &g1, &b1);
                    sum += r1 * m[(x+1)*cols + y];
                }
            }
            pixel = SDL_MapRGB(image_surface->format, r1, g1, b1);
            put_pixel(image_surface,j,i,pixel);
        }
    }
    //possibility to crop image, with white contour this won't matter though


}
