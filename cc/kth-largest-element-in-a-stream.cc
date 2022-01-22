// http://leetcode.com/problems/kth-largest-element-in-a-stream/description/
#include "xxx.hpp"

class KthLargest {
public:
  KthLargest(int k, vector<int> &nums) {
    size_ = k;
    for (auto num : nums) {
      pq_.push(num);
      if (pq_.size() > size_) {
        pq_.pop();
      }
    }
  }

  int add(int val) {
    pq_.push(val);
    if (pq_.size() > size_) {
      pq_.pop();
    }
    return pq_.top();
  }
private:
  int size_;
  priority_queue<int, vector<int>, greater<int>> pq_;
};
