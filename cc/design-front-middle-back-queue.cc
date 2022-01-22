// http://leetcode.com/problems/design-front-middle-back-queue/description/
#include "xxx.hpp"

class FrontMiddleBackQueue {
public:
  FrontMiddleBackQueue() {}

  void pushFront(int val) { lst_.push_front(val); }

  void pushMiddle(int val) {
    const int n = lst_.size();
    auto pos = lst_.begin() + n / 2;
    lst_.insert(pos, val);
  }

  void pushBack(int val) { lst_.push_back(val); }

  int popFront() {
    if (lst_.empty()) {
      return -1;
    }
    auto ret = lst_.front();
    lst_.pop_front();

    return ret;
  }

  int popMiddle() {
    if (lst_.empty()) {
      return -1;
    }
    auto dis = (lst_.size() - 1) / 2;
    auto pos = lst_.begin() + dis;
    int ret = lst_.at(dis);
    lst_.erase(pos);

    return ret;
  }

  int popBack() {
    if (lst_.empty()) {
      return -1;
    }
    auto ret = lst_.back();
    lst_.pop_back();

    return ret;
  }

private:
  deque<int> lst_;
};

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */
