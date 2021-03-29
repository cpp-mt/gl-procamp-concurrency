#include <chrono>
#include <string>

// RAII to put time in microseconds
class TimeLogger 
{
public:
   TimeLogger (const char* operation, size_t threads_no=0);
   ~TimeLogger();
private:
   std::string op_;
   size_t threads_no_;
   std::chrono::time_point<std::chrono::steady_clock> start_tp_;
};

