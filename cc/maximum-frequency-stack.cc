// http://leetcode.com/problems/maximum-frequency-stack/description/
#include "xxx.hpp"

class FreqStack {
public:
  FreqStack() { max_freq_ = 0; }

  void push(int x) {
    freq_[x]++;
    max_freq_ = max(max_freq_, freq_[x]);
    freq_stack_[freq_[x]].push(x);
  }

  int pop() {
    int ret = freq_stack_[max_freq_].top();
    freq_stack_[max_freq_].pop();
    // 当前节点的stack如果为空，最大频率相应往下降
    if (freq_stack_[freq_[ret]].empty()) {
      max_freq_--;
    }
    // 当前节点频率下降
    freq_[ret]--;
    return ret;
  }

private:
  int max_freq_;
  unordered_map<int, int> freq_;
  unordered_map<int, stack<int>> freq_stack_;
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 */
