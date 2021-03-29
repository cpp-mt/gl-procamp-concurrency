#include <thread> 
#include <mutex> 
#include <iostream> 
#include <vector>
#include <chrono>
#include <atomic>

#include "dining_philosophers.h"
//const int Philosophers_No = 5;

constexpr int left(int idx ) { return (idx + (Philosophers_No - 1)) % Philosophers_No; }
constexpr int right(int idx) { return (idx + 1) % Philosophers_No; }

std::mutex fork_mtx[Philosophers_No];
std::atomic<bool> done;

dining_stat summary[Philosophers_No];

void eat(int idx) { 

   //std::cout << "Philosopher "<< idx+1<<" is Hungry"<< std::endl; 

   // take up chopsticks
   fork_mtx[left(idx)].lock();
   fork_mtx[right(idx)].lock();

   // std::cout << "Philosopher "<< idx+1<<" is Eating"<< std::endl; 
   // TODO: uncomment summary update as soon as your code ready for review
   //summary[idx].eat_no++;

   // put chopsticks back
   fork_mtx[right(idx)].unlock();
   fork_mtx[left(idx)].unlock();
} 

// put down chopsticks 
void think(int idx) { 
   //std::cout << "Philosopher " << idx+1 << " is Thinking" << std::endl;
   // TODO: uncomment summary update as soon as your code ready for review
   // summary[idx].think_no++;
} 

void philosopher(int idx) { 
    while (true && !done) { 
	std::this_thread::sleep_for (std::chrono::microseconds(100)); 
	eat(idx); 
	std::this_thread::sleep_for (std::chrono::microseconds(100)); 
	think(idx); 
    } 
} 

void start_dining() {
   //std::cout.sync_with_stdio(true);
   std::vector<std::thread> pool;
   done = false;
   for (int i = 0; i < Philosophers_No; i++) { 
      pool.emplace_back(philosopher, i);
   } 
   for (auto& t : pool) {
      t.join();
   } 
}


