// http://leetcode.com/problems/print-zero-even-odd/description/
#include "xxx.h"

// 多线程编程，运用锁的玩法
class ZeroEvenOdd {

public:
  ZeroEvenOdd(int n) : cur_(0) {
    this->n = n;
    odd_.lock();
    even_.lock();
  }

  // printNumber(x) outputs "x", where x is an integer.
  void zero(function<void(int)> printNumber) {
    for (int i = 0; i < n; ++i) {
      zero_.lock();
      printNumber(0);
      if (++cur_ % 2) {
        odd_.unlock();
      } else {
        even_.unlock();
      }
    }
  }

  void even(function<void(int)> printNumber) {
    for (int i = 0; i < n / 2; ++i) {
      even_.lock();
      printNumber(cur_);
      zero_.unlock();
    }
  }

  void odd(function<void(int)> printNumber) {
    for (int i = 0; i < (n + 1) / 2; ++i) {
      odd_.lock();
      printNumber(cur_);
      zero_.unlock();
    }
  }

private:
  int n;
  int cur_;
  std::mutex zero_;
  std::mutex even_;
  std::mutex odd_;
};
