// http://leetcode.com/problems/design-a-stack-with-increment-operation/description/
#include "xxx.h"

class CustomStack {
public:
  CustomStack(int maxSize) : capacity_(maxSize) {}

  void push(int x) {
    if (vec_.size() < capacity_) {
      vec_.push_back(x);
    }
  }

  int pop() {
    if (vec_.empty()) {
      return -1;
    }
    int ret = vec_.back();
    vec_.pop_back();
    return ret;
  }

  void increment(int k, int val) {
    int len = min(k, (int)vec_.size());
    for (int i = 0; i < len; i++) {
      vec_[i] += val;
    }
  }

private:
  int capacity_;
  vector<int> vec_;
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
