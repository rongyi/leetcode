// http://leetcode.com/problems/exam-room/description/
#include "xxx.hpp"

class ExamRoom {
public:
  ExamRoom(int N) { n_ = N; }

  int seat() {
    // 第一个同学过来直接坐最小的位置结束
    if (seats_.empty()) {
      seats_.insert(0);
      return 0;
    }
    // 策略：找一个最靠左的最大的空间的中间坐下
    int ret = -1;
    auto it = seats_.begin();
    // 如果0没有人坐
    if (*it != 0) {
      // 先假设坐在0这里
      ret = 0;
    }
    // 最大距离
    int diff = *it - 0;
    it++;
    while (it != seats_.end()) {
      int cur_diff = *it - *prev(it);
      if (cur_diff / 2 > diff) {
        ret = *prev(it) + cur_diff / 2;
        diff = cur_diff / 2;
      }
      it++;
    }
    // consider last seats
    if (n_ - 1 - *prev(it) > diff) {
      ret = n_ - 1;
    }
    seats_.insert(ret);
    return ret;
  }

  void leave(int p) { seats_.erase(p); }

private:
  set<int> seats_;
  int n_;
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom* obj = new ExamRoom(N);
 * int param_1 = obj->seat();
 * obj->leave(p);
 */

int main() {
  ExamRoom ex(10);
  ex.seat();
  ex.seat();
  ex.seat();
  ex.leave(0);
}
