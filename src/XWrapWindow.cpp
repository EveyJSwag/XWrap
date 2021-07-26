#include "XWrapWindow.h"

XWrapWindow::XWrapWindow()
{
   positionSize = position_size();
   blackWhitePixel = black_white_pixel(0xFFF, 0xFFFFFFFF);
}

XWrapWindow::XWrapWindow(
   position_size& aPositionSize, 
   black_white_pixel& aBlackWhitePixel)
{
   positionSize = aPositionSize;
   blackWhitePixel = aBlackWhitePixel;
}

void XWrapWindow::createSimpleWindow()
{
   window = XCreateSimpleWindow(
               getDisplay(),
               RootWindow(getDisplay(), 0),
               positionSize.x, positionSize.y,
               positionSize.width, positionSize.height,
               2,
               blackWhitePixel.blackPixel, blackWhitePixel.whitePixel);

   if (!window) 
      throw XWrapException(__LINE__, __FILE__);
   else
   {
      XSetWindowAttributes newAttributes;
      newAttributes.override_redirect = 0;
      newAttributes.event_mask = 0xFFFFFF;


      attribute_setter = new XWrapWindow::AttributeSetter(
         window, 
         getDisplay(), 
         CWOverrideRedirect | CWEventMask,
         newAttributes);

      XMapWindow(getDisplay(), window);
   }
}

XWrapWindow::AttributeSetter::AttributeSetter(         
   Window& aWindowReference,
   Display* aDisplayReference,
   unsigned long aAttributeMask,
   XSetWindowAttributes& aNewAttribute)
{
   new_attribute  = aNewAttribute;
   window_reference = aWindowReference;
   display_reference = aDisplayReference;
   attribute_mask = aAttributeMask;
   if (!XChangeWindowAttributes(
           display_reference, 
           window_reference, 
           attribute_mask,
           &new_attribute))
   {
      throw new XWrapException(__LINE__, __FILE__);
   }
}
