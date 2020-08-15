// http://leetcode.com/problems/print-in-order/description/
#include "xxx.h"

class Foo {
public:
  Foo() : count_{0} {}

  void first(function<void()> printFirst) {

    std::lock_guard<std::mutex> guard(m_);
    ++count_;
    // printFirst() outputs "first". Do not change or remove this line.
    printFirst();
  }

  void second(function<void()> printSecond) {

    while (count_ < 1) {
    }
    std::lock_guard<std::mutex> guard(m_);
    ++count_;
    // printSecond() outputs "second". Do not change or remove this line.
    printSecond();
  }

  void third(function<void()> printThird) {

    while (count_ < 2) {
    }
    std::lock_guard<std::mutex> guard(m_);
    // printThird() outputs "third". Do not change or remove this line.
    printThird();
  }

private:
  mutable std::mutex m_;
  int count_;
};
