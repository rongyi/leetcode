// http://leetcode.com/problems/my-calendar-iii/description/
#include "xxx.h"

class MyCalendarThree {
public:
  MyCalendarThree() {}

  int book(int start, int end) {
    timeline_[start]++;
    timeline_[end]--;
    int ongoing = 0;
    int ret = 0;
    for (auto &kv : timeline_) {
      ret = max(ret, ongoing += kv.second);
    }

    return ret;
  }

private:
  map<int, int> timeline_;
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */
