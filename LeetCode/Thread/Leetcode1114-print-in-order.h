#include <condition_variable>
#include <functional>
#include <mutex>
#include <thread>


using namespace std;


class Foo {
public:
  int tag_ = 0;
  std::condition_variable cv_;
  std::mutex mx_;

  Foo() {}

  void first(function<void()> printFirst) {
    // printFirst() outputs "first". Do not change or remove this line.
    printFirst();
    tag_ = 1;
    cv_.notify_all();
  }

  void second(function<void()> printSecond) {
    std::unique_lock<std::mutex> lk(mx_);
    cv_.wait(lk, [this]() { return tag_ == 1; });
    // printSecond() outputs "second". Do not change or remove this line.
    printSecond();
    tag_ = 2;
    lk.unlock();
    cv_.notify_one();
  }

  void third(function<void()> printThird) {
    std::unique_lock<std::mutex> lk(mx_);
    cv_.wait(lk, [this]() { return tag_ == 2; });
    // printThird() outputs "third". Do not change or remove this line.
    printThird();
    tag_ = 3;
    lk.unlock();
    cv_.notify_one();
  }
};

// 还可以用promise + future或者package_task + future来实现
