#include <iostream>
#include <thread>
#include <chrono>

class ThreadContainer
{
    
    std::thread t;

public:
    ThreadContainer(std::thread&& otherTh) : t(std::move(otherTh)) {}

    ~ThreadContainer() {
        if (t.joinable()) {
            t.join();
        }
    }

    // to support moving
    ThreadContainer(ThreadContainer&&) = default;
    ThreadContainer& operator=(ThreadContainer&&) = default;
};

void division(int a, int b)
{
    if (b == 0)
        throw std::overflow_error("Divide by zero exception");
    std::cout << "Div " << float(a) / b << '\n';
}

void addition(int a, int b)
{
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout << "Add " << a + b << '\n';
}

void doMaths()
{
    ThreadContainer(std::thread(addition, 2, 3));
    ThreadContainer(std::thread(division, 2, 0));
    throw std::runtime_error("random error");
    /*
    std::thread t1(addition, 2, 3);
    std::thread t2(division, 2, 4);
    throw std::runtime_error("random error");
    t1.join();
    t2.join();
    */
}

int main()
try {
    doMaths();
    char ch;
    std::cin >> ch;
}
catch(std::exception& e) {
   std::cout << "exception in main :" <<e.what() << std::endl;
}
