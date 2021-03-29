#include "time_logger.h"

namespace {
void func(int iterations, int& counter)
{
   for (int i = 0; i < iterations; ++i) {
      ++counter;
   }
}
}
int count_st(int iterations)
{
   int counter = 0;
   TimeLogger log("single-threaded counter");
   func(iterations, counter);
   return counter;
}
