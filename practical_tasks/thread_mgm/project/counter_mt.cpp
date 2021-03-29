#include <thread>
#include <algorithm>
#include <vector>
#include <functional>

namespace {
   void func(int iterations, int& counter)
   {
      for (int i = 0; i < iterations; ++i) {
         ++counter;
      }
   }
}

int count_mt(int iterations)
{
   int counter = 0;

   // ADD you MT implementation here
   return counter;
}
