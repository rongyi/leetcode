// https://leetcode.com/problems/smallest-number-in-infinite-set/
#include "xxx.hpp"

class SmallestInfiniteSet {
public:
  SmallestInfiniteSet() { range_start_ = 1; }

  int popSmallest() {
    if (!dot_.empty()) {
      auto it = dot_.begin();
      int ret = *it;
      dot_.erase(it);
      return ret;
    }

    int ret = range_start_++;
    return ret;
  }

  void addBack(int num) {
    if (num < range_start_) {
      dot_.insert(num);
    }
  }

private:
  // put all add back single num to here
  set<int> dot_;
  // the range start
  int range_start_;
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
