// https://leetcode.com/problems/find-consecutive-integers-from-a-data-stream/
#include "xxx.hpp"

class DataStream {
public:
  DataStream(int value, int k) : value_(value), k_(k), diff_pos_(0) {}

  bool consec(int num) {
    if (num != value_) {
      diff_pos_ = 0;
    } else {
      diff_pos_++;
    }

    return diff_pos_ >= k_;
  }

private:
  int value_;
  int k_;
  int diff_pos_;
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */
