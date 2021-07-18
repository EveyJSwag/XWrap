#ifndef XWRAPWINDOW_H
#define XWRAPWINDOW_H

#include "XWrapMain.h"
#include "XWrapWindowTypes.h"
#include "XWrapException.h"

class XWrapWindow : public XWrapMain
{
private:
   Window window;
   position_size positionSize;
   black_white_pixel blackWhitePixel;
public:
   XWrapWindow();

   XWrapWindow(
      position_size& aPositionSize,
      black_white_pixel& aBlackWhitePixel);

   void createSimpleWindow();

   class AttributeSetter
   {
   public:
      AttributeSetter(
         Window& aWindowReference,
         Display* aDisplayReference,
         unsigned long aAttributeMask,
         XSetWindowAttributes& aNewAttribute);
   private:
      XSetWindowAttributes new_attribute;
      Window window_reference;
      Display* display_reference;
      unsigned long attribute_mask;
   };

private:
   XWrapWindow::AttributeSetter* attribute_setter;
};

#endif