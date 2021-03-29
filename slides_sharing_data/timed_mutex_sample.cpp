#include <vector>
#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

std::timed_mutex m;
//std::mutex m;  // cause compilation error: 
                 // 'try_lock_for': is not a member of 'std::mutex'

void doWork() {
   for (int i = 0; i < 10000; ++i) {
        std::unique_lock<std::timed_mutex> lock(m, std::defer_lock);
        int count = 0;
        while (!lock.try_lock_for(std::chrono::microseconds(1))) {
            ++count;
        }
        std::cout << count << '\n';		
    }	
}

int main() {
    std::vector<std::thread> workers;
    for (int i = 0; i < 16; ++i) {
        workers.emplace_back(doWork);		
    }
    for (auto& t : workers) { t.join(); }	
}
