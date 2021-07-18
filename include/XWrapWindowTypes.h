#ifndef XWRAPWINDOWTYPES_H
#define XWRAPWINDOWTYPES_H
#include <X11/X.h>
typedef struct position_size
{
    position_size(
       int aX, 
       int aY, 
       unsigned int aWidth, 
       unsigned int aHeight);

    position_size();

    int x;
    int y;
    unsigned int width;
    unsigned int height;
} position_size;

typedef struct black_white_pixel
{
    black_white_pixel(
       unsigned long aBlackPixel,
       unsigned long aWhitePixel);

    black_white_pixel();

    unsigned long blackPixel;
    unsigned long whitePixel;
} black_white_pixel;
#define ALL_EVENTS DestroyNotify
//KeyPress	| KeyRelease | ButtonPress	|ButtonRelease	|MotionNotify	|EnterNotify	|LeaveNotify	|FocusIn		|FocusOut		|KeymapNotify	| Expose			|GraphicsExpose	| NoExpose		|VisibilityNotify| CreateNotify	| DestroyNotify	| UnmapNotify | MapNotify | MapRequest	 | ReparentNotify	| ConfigureNotify | ConfigureRequest | GravityNotify	| ResizeRequest	| CirculateNotify	| CirculateRequest| PropertyNotify	| SelectionClear	| SelectionRequest| SelectionNotify	| ColormapNotify | ClientMessage	| MappingNotify	| GenericEvent	| LASTEvent

#endif