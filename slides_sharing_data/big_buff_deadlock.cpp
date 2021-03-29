#include <mutex>
#include <thread>
#include <utility>
#include <vector>

class BigBuf // A Big Buffer
{
public:
    static constexpr long size() { return 16 * 1024L * 1024L; }
    BigBuf() : data_(size()) {}
    BigBuf& operator=(const BigBuf&) = delete;
    BigBuf& operator=(BigBuf&&) = delete;
    void swap(BigBuf& other) {
        if (this == &other) { return; }
        // acquiring the two mutexes in this way can result in deadlock
        std::lock_guard lock1(m_);
        std::lock_guard lock2(other.m_);
        std::swap(data_, other.data_);

    }
    // ...
private:
    std::vector<char> data_;
    mutable std::mutex m_;
};

BigBuf a;
BigBuf b;

int main() {
    std::thread t1([]() {
        for (long i = 0; i < 1'000'000; ++i) a.swap(b);
        });
    std::thread t2([]() {
        for (long i = 0; i < 1'000'000; ++i) b.swap(a);
        });
    t1.join(); t2.join();
}
