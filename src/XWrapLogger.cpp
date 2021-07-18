#include "XWrapLogger.h"
#include "XWrapException.h"
#include <sstream>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>
XWrapLogger::XWrapLogger()
{
   fileDescriptor = open(
                       DEFAULT_LOG_FILE.c_str(), 
                       5);

   if (!fileDescriptor)
   {
      throw new XWrapException(__LINE__, __FILE__);
   }
}

void XWrapLogger::logX11Event(const int& aXEvent)
{
   time_t logTime = time(NULL);
   time_t logTimeHours = logTime / 3600;
   time_t logTimeYears = logTimeHours / 8760;
   std::ostringstream eventLogStream;
   eventLogStream << "X11 EVENT: ";
   switch(aXEvent)
   {
      case 2:  
         eventLogStream << "KeyPress";            
         break;
      case 3:  
         eventLogStream << "KeyRelease"; 	
         break;
      case 4:  
         eventLogStream << "ButtonPress"; 	
         break;
      case 5:  
         eventLogStream << "ButtonRelease"; 		
         break;
      case 6:  
         eventLogStream << "MotionNotify"; 	
         break;
      case 7:  
         eventLogStream << "EnterNotify";
         break;
      case 8:  
         eventLogStream << "LeaveNotify"; 	
         break;
      case 9:  
         eventLogStream << "FocusIn";
         break;
      case 10: 
         eventLogStream << "FocusOut";	        
         break;
      case 11: 
         eventLogStream << "KeymapNotify";
         break;
      case 12: 
         eventLogStream << "Expose";
         break;
      case 13: 
         eventLogStream << "GraphicsExpose";
         break;
      case 14: 
         eventLogStream << "NoExpose";  
         break;
      case 15: 
         eventLogStream << "VisibilityNotify";
         break;
      case 16: 
         eventLogStream << "CreateNotify";
         break;
      case 17: 
         eventLogStream << "DestroyNotify";	
         break;
      case 18: 
         eventLogStream << "UnmapNotify";
         break;
      case 19: 
         eventLogStream << "MapNotify";	   
         break; 
      case 20: 
         eventLogStream << "MapRequest";
         break;
      case 21: 
         eventLogStream << "ReparentNotify";		
         break;
      case 22: 
         eventLogStream << "ConfigureNotify";		
         break;
      case 23: 
         eventLogStream << "ConfigureRequest";	
         break;
      case 24: 
         eventLogStream << "GravityNotify";
         break;
      case 25: 
         eventLogStream << "ResizeRequest";	
         break;
      case 26: 
         eventLogStream << "CirculateNotify";		
         break;
      case 27: 
         eventLogStream << "CirculateRequest";	
         break;
      case 28: 
         eventLogStream << "PropertyNotify";
         break;
      case 29: 
         eventLogStream << "SelectionClear";
         break;
      case 30: 
         eventLogStream << "SelectionRequest";	
         break;
      case 31: 
         eventLogStream << "SelectionNotify";
         break;
      case 32: 
         eventLogStream << "ColormapNotify";
         break;
      case 33: 
         eventLogStream << "ClientMessage";
         break;
      case 34: 
         eventLogStream << "MappingNotify";
         break;
      case 35: 
         eventLogStream << "GenericEvent";
         break;
      case 36: 
         eventLogStream << "LASTEvent";
         break;
   }
   eventLogStream << "\n";
   if (write(fileDescriptor, eventLogStream.str().c_str(), eventLogStream.str().size()) < 0)
   {
      throw new XWrapException(__LINE__,__FILE__);
   }
}
XWrapLogger::~XWrapLogger()
{
   close(fileDescriptor);
   delete this;
}
	