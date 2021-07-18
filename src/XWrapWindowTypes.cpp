#include "XWrapWindowTypes.h"

position_size::position_size(       
   int aX, int aY, 
   unsigned int aWidth, unsigned int aHeight)
{
   x = aX;
   y = aY;
   width = aWidth;
   height = aHeight;
}

position_size::position_size()
{
   x = 0;
   y = 0;
   width = 200;
   height = 200;
}

black_white_pixel::black_white_pixel(
   unsigned long aBlackPixel,
   unsigned long aWhitePixel)
{
   blackPixel = aBlackPixel;
   whitePixel = aWhitePixel;
}

black_white_pixel::black_white_pixel()
{
   whitePixel = 0;
   blackPixel = 0;
}
