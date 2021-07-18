#include "XWrapMain.h"
#include "XWrapException.h"
XWrapMain::XWrapMain()
{
   display = XOpenDisplay(NULL);

   if (!display)
      throw XWrapException(__LINE__, __FILE__);
}