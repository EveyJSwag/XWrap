#include "XWrapException.h"
#include <sstream>

XWrapException::XWrapException(unsigned int line, const char* file)
{
   std::ostringstream exceptionBuffer;
   exceptionBuffer 
      << what() << ":" << "\n" 
      << file << ": " << line;

   detailedException = exceptionBuffer.str();
}