// http://leetcode.com/problems/implement-stack-using-queues/description/
#include "simpleone.h"

class MyStack {
public:
  /** Initialize your data structure here. */
  MyStack() {}

  /** Push element x onto stack. */
  void push(int x) {
    // 让q2全部滚到q1里去
    while (!q2.empty()) {
      q1.push(q2.front());
      q2.pop();
    }
    q2.push(x);
  }

  /** Removes the element on top of the stack and returns that element. */
  int pop() {
    auto i = top();
    q2.pop();

    return i;
  }

  /** Get the top element. */
  int top() {
    // 保证q2里有东西
    if (q2.empty()) {
      // q1转呀转,把最后一个元素暴露在最头面
      for (int i = 0; i < q1.size() - 1; ++i) {
        q1.push(q1.front());
        q1.pop();
      }

      q2.push(q1.front());
      q1.pop();
    }

    return q2.front();
  }

  /** Returns whether the stack is empty. */
  bool empty() { return q1.empty() && q2.empty(); }

private:
  // help q2 to be a stack
  queue<int> q1;
  // for insert
  // 有元素过来先插入q2，然后保证q2里面至多有一个，这样pop的时候直接出p2即可
  queue<int> q2;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * bool param_4 = obj.empty();
 */
