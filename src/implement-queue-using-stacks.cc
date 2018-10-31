// http://leetcode.com/problems/implement-queue-using-stacks/description/
#include "simpleone.h"

class MyQueue {
public:
  /** Initialize your data structure here. */
  MyQueue() {}

  /** Push element x to the back of queue. */
  void push(int x) {
    left_.push(x);
  }

  /** Removes the element from in front of queue and returns that element. */
  int pop() {
    auto i = peek();
    right_.pop();

    return i;
  }

  /** Get the front element. */
  int peek() {
    if (right_.empty()) {
      while (!left_.empty()) {
        right_.push(left_.top());
        left_.pop();
      }
    }
    return right_.top();
  }

  /** Returns whether the queue is empty. */
  bool empty() {
    return left_.empty() && right_.empty();
  }
private:
  stack<int> left_;
  stack<int> right_;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */
