#include <thread>
#include <atomic>
#include <vector>
#include <functional>
#include <iostream>

#include "joiner.h"
#include "thread_safe_queue_revised.h"

class thread_pool {
	std::atomic_bool done;
	thread_safe_queue<std::function<void()> > work_queue;
	std::vector<std::thread> threads;
	join_threads joiner;
public:
	void worker_thread() {
		std::cout << "worker thread: "<< std::this_thread::get_id()<<" started\n";
		while (!done) {
			std::function<void()> task;
			if (work_queue.try_pop(task)) {
				//std::cout << "worker thread "<< std::this_thread::get_id()<<" execute task...\n";
				task();
			}
			else {
				//std::cout << "queue empty\n";
				std::this_thread::yield();
			}
		}
	}
public:
	thread_pool() :		// done(false),   // compilation error, VS issue
		joiner(threads), done(false) {
		//done = false; 
		unsigned const thread_count = std::thread::hardware_concurrency();
                std::cout << "threads no = "<< thread_count << "\n";
		try {
			for (unsigned i = 0; i < thread_count; ++i) {
				threads.push_back( std::thread(&thread_pool::worker_thread, this));
			}
		}
		catch (...) {
			done = true;
			throw;
		}
	}

	~thread_pool() {
		done = true;
		std::cout << "~thread_pool()\n";
	}

	template<typename FunctionType>	void submit(FunctionType f) {
		work_queue.push(std::function<void()>(f));
	}
};

void task() {
   std::cout << "task on thread "<< std::this_thread::get_id() << std::endl;
   return;
}

int main() {
   std::cout << "start thread pool\n";
   thread_pool tp;
   for (int i = 0; i < 16; ++i) {
	tp.submit(task);
   }
   //std::this_thread::sleep_for(std::chrono::seconds(2)); 
   std::cout << "launched jobs\n";
}
