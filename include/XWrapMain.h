#ifndef XWRAPMAIN_H
#define XWRAPMAIN_H

#include <X11/Xlib.h>

class XWrapMain
{
public:
   XWrapMain();
   Display* getDisplay() {return display;}
private:
   Display* display;
};

#endif