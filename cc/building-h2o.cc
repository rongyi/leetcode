// http://leetcode.com/problems/building-h2o/description/
#include "xxx.hpp"


class H2O {
public:
  // OHH valid
  // HOH valid
  H2O() : count_(0) {
    hmutex_.lock();
    omutex_.lock();
    hmutex_.unlock();
  }

  void hydrogen(function<void()> releaseHydrogen) {
    hmutex_.lock();
    ++count_;

    // releaseHydrogen() outputs "H". Do not change or remove this line.
    releaseHydrogen();
    if ((count_ % 2) == 1) {
      hmutex_.unlock();
    } else {
      omutex_.unlock();
    }
  }

  void oxygen(function<void()> releaseOxygen) {
    omutex_.lock();

    // releaseOxygen() outputs "O". Do not change or remove this line.
    releaseOxygen();
    hmutex_.unlock();
  }
private:
  int count_;

  mutex hmutex_;
  mutex omutex_;
};
