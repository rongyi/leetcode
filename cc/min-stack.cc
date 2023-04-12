// http://leetcode.com/problems/min-stack/description/
#include "xxx.hpp"

class MinStack {
public:
  MinStack() {}

  void push(int val) {
    normal_.push(val);
    if (min_.empty()) {
      min_.push(val);
    } else {
      min_.push(min(val, min_.top()));
    }
  }

  void pop() {
    normal_.pop();
    min_.pop();
  }

  int top() { return normal_.top(); }

  int getMin() { return min_.top(); }

private:
  stack<int> normal_;
  stack<int> min_;
};
