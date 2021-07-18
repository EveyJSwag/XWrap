#ifndef XWRAPLOGGER_H
#define XWRAPLOGGER_H

#include <iostream>

const std::string DEFAULT_LOG_FILE = "logging/xwrap.log";

class XWrapLogger
{
public:
   XWrapLogger();
   void logX11Event(const int& aXEvent);
   ~XWrapLogger();
private:
   int fileDescriptor;
};
#endif 