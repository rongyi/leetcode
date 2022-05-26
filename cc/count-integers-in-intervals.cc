// https://leetcode.com/problems/count-integers-in-intervals/
#include "xxx.hpp"

class CountIntervals {
public:
  CountIntervals() : cnt_(0) {}

  void add(int left, int right) {
    auto it = range_.upper_bound(left);
    // see if the prev range can be intersectioned
    // e.g. [1, 3] before [left, right] -> [3, 5]
    // now we should merge to [1, 5]
    if (it != range_.begin() && prev(it)->second >= left) {
      it = prev(it);
    }

    for (; it != range_.end() && it->first <= right; range_.erase(it++)) {
      left = min(left, it->first);
      right = max(right, it->second);
      cnt_ -= it->second - it->first + 1;
    }
    cnt_ += right - left + 1;
    range_[left] = right;
  }

  int count() { return cnt_; }

private:
  // start -> end
  map<int, int> range_;
  int cnt_;
};

/**
 * Your CountIntervals object will be instantiated and called as such:
 * CountIntervals* obj = new CountIntervals();
 * obj->add(left,right);
 * int param_2 = obj->count();
 */

int main(int argc, char *argv[]) {
  CountIntervals ci;

  ci.add(2, 3);
  ci.add(7, 10);

  cout << ci.count() << endl;

  ci.add(5, 8);
  cout << ci.count() << endl;

  return 0;
}
