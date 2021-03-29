#include <thread>
#include <iostream>
#include <memory>
#include <mutex>

std::mutex m;

void init()
{
  static thread_local std::unique_ptr<bool> tls;
  if (!tls.get())
  {
    tls.reset(new bool{true});
    std::lock_guard<std::mutex> lock{m};
    std::cout << "done" << '\n';
  }
}

void thread()
{
  init();
  init();
}

int main()
{
  std::thread t[3];

  for (int i = 0; i < 3; ++i)
    t[i] = std::thread{thread};

  for (int i = 0; i < 3; ++i)
    t[i].join();
}
