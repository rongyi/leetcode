// http://leetcode.com/problems/my-calendar-i/description/
#include "xxx.h"

class MyCalendar {
public:
  MyCalendar() {}

  bool book(int start, int end) {
    if (data_.empty()) {
      data_.push_back({start, end});
      return true;
    }
    for (int i = 0; i < data_.size(); i++) {
      auto &cur = data_[i];
      if (end <= cur.first || start >= cur.second) {
        continue;
      }
      return false;
    }
    data_.push_back({start, end});
    return true;
  }

private:
  vector<pair<int, int>> data_;
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
