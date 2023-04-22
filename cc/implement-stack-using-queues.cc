// http://leetcode.com/problems/implement-stack-using-queues/description/
#include "xxx.hpp"

class MyStack {
public:
  MyStack() {}

  void push(int x) {
    q_.push(x);
    // rotate to expose the last one to front
    for (int i = 0; i < q_.size() - 1; i++) {
      auto val = q_.front();
      q_.pop();
      q_.push(val);
    }
  }

  int pop() {
    int val = q_.front();
    q_.pop();
    return val;
  }

  int top() { return q_.front(); }

  bool empty() { return q_.empty(); }

private:
  queue<int> q_;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
