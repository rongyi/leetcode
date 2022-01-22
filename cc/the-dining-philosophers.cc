// http://leetcode.com/problems/the-dining-philosophers/description/
#include "xxx.hpp"

class DiningPhilosophers {
public:
  DiningPhilosophers() {}

  void wantsToEat(int philosopher, function<void()> pickLeftFork,
                  function<void()> pickRightFork, function<void()> eat,
                  function<void()> putLeftFork, function<void()> putRightFork) {
    // clock wise order
    int left = philosopher;
    // so the right fork is index - 1;
    int right = (philosopher + 4 /* -1 + 5 */) % 5;
    bool even = philosopher % 2 == 0;

    int first = even ? left : right;
    int second = left + right - first;

    unique_lock<mutex> lock1(m_[first]);
    unique_lock<mutex> lock2(m_[second]);

    pickLeftFork();
    pickRightFork();
    eat();
    putLeftFork();
    putRightFork();
  }
  mutex m_[5];
};
