#include <thread>
#include <iostream>

// main thread ID
std::thread::id mainThread;

void func() {
   if (std::this_thread::get_id() == mainThread) {
      std::cout << "called by main thread\n";
   } else {
      std::cout << "called by secondary thread\n";
   }
}

int main() {
   mainThread = std::this_thread::get_id();
   std::thread t([](){
   // call func from secondary thread
      func();
   });
   // call func from main thread
   func();
   t.join();
}
