// http://leetcode.com/problems/min-stack/description/
#include "one.h"

class MinStack {
public:
  /** initialize your data structure here. */
  MinStack() {}

  void push(int x) {
    if (normal_.empty()) {
      normal_.push(x);
      // the min_ must be also empty
      min_.push(x);
      return;
    }
    auto cur = min_.top();
    // 注意这里相等的情况，也要push进去，保证不递增就可以
    if (x <= cur) {
      min_.push(x);
    }
    normal_.push(x);
  }

  void pop() {
    if (normal_.empty()) {
      return;
    }
    auto cur = normal_.top();
    if (cur == min_.top()) {
      min_.pop();
    }
    normal_.pop();
  }

  int top() {
    if (normal_.empty()) {
      return -1;
    }
    return normal_.top();
  }

  int getMin() {
    if (min_.empty()) {
      return -1;
    }
    return min_.top();
  }
private:
  stack<long long> normal_;
  stack<long long> min_;
};
int main() {
  MinStack ms;
  auto cur = numeric_limits<int>::max();
  ms.push(cur);
  ms.push(cur);
  ms.pop();
  auto tmp = ms.getMin();
  cout << tmp << endl;
}


/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
