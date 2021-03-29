#include "time_logger.h"
#include <iostream>
#include <sstream>

using namespace std;

TimeLogger::TimeLogger(const char* operation, size_t threads_no): 
	op_(operation),
	threads_no_ (threads_no)
{
   start_tp_ = chrono::steady_clock::now();
}

TimeLogger::~TimeLogger()
{
   auto tp = std::chrono::steady_clock::now();
   std::ostringstream str;
   str << op_ << " took: "
        << chrono::duration_cast<chrono::microseconds>(tp - start_tp_).count()
	<< " microseconds ";
   if (threads_no_ > 0)
      str << "(threads: "<< threads_no_ <<")";
   cout <<str.str()<<endl;
}
