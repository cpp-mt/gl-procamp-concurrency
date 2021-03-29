#include <iostream>
#include <vector>
#include <thread>
#include <functional>

void func(int& counter)
{
   int tmp = 0;
   for (int i = 0; i < 100000; ++i) {
      //++counter;
      ++tmp;
   }
   counter+=tmp;
}

int main()
{
   int counter = 0;
   std::vector<std::thread> threads;
   for (int i = 0; i < 3; ++i) {
      threads.push_back(std::thread{func, std::ref(counter)});
   }
   func(counter);
   for (auto& t : threads) {
      t.join();
   }
   std::cout << "Result = " << counter << std::endl;
   return 0;
}

