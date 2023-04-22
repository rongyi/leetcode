// http://leetcode.com/problems/implement-queue-using-stacks/description/
#include "xxx.hpp"

class MyQueue {
public:
  MyQueue() {}

  void push(int x) { stk1_.push(x); }

  int pop() {
    if (stk2_.empty()) {
      while (!stk1_.empty()) {
        stk2_.push(stk1_.top());
        stk1_.pop();
      }
    }

    int val = stk2_.top();
    stk2_.pop();

    return val;
  }

  int peek() {
    if (stk2_.empty()) {
      while (!stk1_.empty()) {
        stk2_.push(stk1_.top());
        stk1_.pop();
      }
    }

    return stk2_.top();
  }

  bool empty() { return stk1_.empty() && stk2_.empty(); }

private:
  // for push
  stack<int> stk1_;
  // for pop
  stack<int> stk2_;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
