// http://leetcode.com/problems/dinner-plate-stacks/description/
#include "xxx.h"

class DinnerPlates {
public:
  DinnerPlates(int capacity) : cap_(capacity), push_pos_(0), pop_pos_(0) {}

  void push(int val) {
    if (plates_.size() == push_pos_) {
      plates_.push_back({});
    }
    if (plates_[push_pos_].size() == cap_) {
      ++push_pos_;
      push(val);
    } else {
      pop_pos_ = max(pop_pos_, push_pos_);
      plates_[push_pos_].push(val);
    }
  }

  int pop() {
    if (plates_.empty()) {
      return -1;
    }
    if (plates_[pop_pos_].size() == 0) {
      if (pop_pos_ == 0) {
        return -1;
      }
      --pop_pos_;
      return pop();
    }
    int ret = plates_[pop_pos_].top();
    plates_[pop_pos_].pop();
    push_pos_ = min(push_pos_, pop_pos_);

    return ret;
  }

  int popAtStack(int index) {
    if (plates_.size() <= index || plates_[index].size() == 0) {
      return -1;
    }
    int ret = plates_[index].top();
    plates_[index].pop();
    push_pos_ = min(push_pos_, index);
    return ret;
  }

private:
  // two pointers
  // easy to understand but wast memory
  int cap_;
  int push_pos_;
  int pop_pos_;
  vector<stack<int>> plates_;
};

/**
 * Your DinnerPlates object will be instantiated and called as such:
 * DinnerPlates* obj = new DinnerPlates(capacity);
 * obj->push(val);
 * int param_2 = obj->pop();
 * int param_3 = obj->popAtStack(index);
 */
