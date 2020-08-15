// http://leetcode.com/problems/fizz-buzz-multithreaded/description/
#include "xxx.h"

class FizzBuzz {

public:
  FizzBuzz(int n) : cur_(1) {
    this->n_ = n;
    flock_.lock();
    block_.lock();
    fblock_.lock();
    // open num lock
  }

  // printFizz() outputs "fizz".
  void fizz(function<void()> printFizz) {
    while (true) {
      flock_.lock();
      if (cur_ > n_) {
        break;
      }
      printFizz();
      next();
    }
  }

  // printBuzz() outputs "buzz".
  void buzz(function<void()> printBuzz) {
    while (true) {
      block_.lock();
      if (cur_ > n_) {
        break;
      }
      printBuzz();
      next();
    }
  }

  // printFizzBuzz() outputs "fizzbuzz".
  void fizzbuzz(function<void()> printFizzBuzz) {
    while (true) {
      fblock_.lock();
      if (cur_ > n_) {
        break;
      }
      printFizzBuzz();
      next();
    }
  }

  // printNumber(x) outputs "x", where x is an integer.
  void number(function<void(int)> printNumber) {
    while (true) {
      numlock_.lock();
      if (cur_ > n_) {
        break;
      }
      printNumber(cur_);
      next();
    }
  }

private:
  void next() {
    ++cur_;
    if (cur_ > n_) {
      flock_.unlock();
      block_.unlock();
      fblock_.unlock();
      numlock_.unlock();
    } else if (!(cur_ % 15)) {
      fblock_.unlock();
    } else if (!(cur_ % 5)) {
      block_.unlock();
    } else if (!(cur_ % 3)) {
      flock_.unlock();
    } else {
      numlock_.unlock();
    }
  }

private:
  int cur_;
  int n_;
  mutex flock_;
  mutex block_;
  mutex fblock_;
  mutex numlock_;
};
