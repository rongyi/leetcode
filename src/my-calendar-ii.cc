// http://leetcode.com/problems/my-calendar-ii/description/
#include "xxx.h"

class MyCalendar {
  vector<pair<int, int>> books;

public:
  bool book(int start, int end) {
    for (pair<int, int> p : books)
      if (max(p.first, start) < min(end, p.second))
        return false;
    books.push_back({start, end});
    return true;
  }
};

class MyCalendarTwo {
public:
  MyCalendarTwo() {}

  bool book(int start, int end) {
    MyCalendar non_colision;
    for (auto &p : data_) {
      // overlap exist
      if (max(p.first, start) < min(end, p.second)) {
        pair<int, int> intersection = {max(start, p.first), min(end, p.second)};
        // 冲突的空间不能再冲突了，所以这里的冲突地方就放在之前的
        // MyCalendar的地方
        if (!non_colision.book(intersection.first, intersection.second)) {
          return false;
        }
      }
    }
    data_.push_back({start, end});
    return true;
  }

private:
  vector<pair<int, int>> data_;
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */
