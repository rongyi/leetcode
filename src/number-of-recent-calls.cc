// http://leetcode.com/problems/number-of-recent-calls/description/
#include "xxx.h"

// 喷的特别惨的一道题
class RecentCounter {
public:
  RecentCounter() {}

  // 就是个sliding window
  int ping(int t) {
    q_.push(t);
    if (t < 3000) {
      return q_.size();
    }
    auto last = q_.back();
    last -= 3000;
    while (!q_.empty() && q_.front() < last) {
      q_.pop();
    }
    return q_.size();
  }
private:
  queue<int> q_;
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
