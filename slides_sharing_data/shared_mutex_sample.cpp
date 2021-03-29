#include <thread>
#include <mutex>
#include <iostream>
#include <vector>
#include <shared_mutex>

std::mutex coutMutex;
int counter = 0;
std::shared_mutex counterMutex;

void writer() {
    for (int i = 0; i < 10; ++i) {
        {
            std::lock_guard<std::shared_mutex> lock(counterMutex);
            ++counter;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(100));

    }

}

void reader() {
    for (int i = 0; i < 100; ++i) {
        int c;
        {
            std::shared_lock<std::shared_mutex> lock(counterMutex);
            c = counter;
        }
        {
            std::lock_guard<std::mutex> lock(coutMutex);
            std::cout << std::this_thread::get_id() << ' ' << c << '\n';
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(10));

    }

}

int main() {
    std::vector<std::thread> threads;
    threads.emplace_back(writer);
    for (int i = 0; i < 16; ++i) threads.emplace_back(reader);
    for (auto& t : threads) t.join();

}
