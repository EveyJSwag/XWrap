#ifndef XWRAPEXCEPTION_H
#define XWRAPEXCEPTION_H

#include <iostream>
class XWrapException : public std::exception
{
public:

   XWrapException(unsigned int line, const char* file);
   std::string getExceptionDetail() { return detailedException; }
   const char* what() const noexcept override
   {
      return "XWrapException";
   }

private:
   std::string detailedException;

};

#endif