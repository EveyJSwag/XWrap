#include "XWrapMain.h"
#include "XWrapWindow.h"
#include "XWrapLogger.h"
#include <stdlib.h>
#include <string.h>
#include <iostream>
int main()
{
   XWrapWindow* xwrapwindow = NULL;
   XWrapLogger* xwraplogger = NULL;
   try
   {
      xwraplogger = new XWrapLogger();
      xwrapwindow = new XWrapWindow();
      xwrapwindow->createSimpleWindow();

      XEvent event = {0};

      while(1)
      {
         XNextEvent(xwrapwindow->getDisplay(), &event);

         xwraplogger->logX11Event(event.type);
      }

      //delete xwraplogger;

   }
   catch (XWrapException* e)
   {
      std::cerr << e->getExceptionDetail();
   }
   catch(const std::exception& e)
   {
      std::cerr << e.what();
   }
   catch (const std::exception* e)
   {
      std::cerr << e->what();
   }
}