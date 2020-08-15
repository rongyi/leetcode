// https://leetcode.com/problems/lemonade-change/description/

#include "xxx.h"

class Solution {
public:
  bool lemonadeChange(vector<int> &bills) {
    int cnt5 = 0;
    int cnt10 = 0;
    const int n = bills.size();

    for (int i = 0; i < n; ++i) {
      if (bills[i] == 5) {
        ++cnt5;
      } else if (bills[i] == 10) {
        ++cnt10;
        if (cnt5 == 0) {
          return false;
        }
        // 找人家5块钱
        --cnt5;
      } else {
        // 一张10块，一张5块
        if (cnt10 > 0 && cnt5 > 0) {
          --cnt10;
          --cnt5;
        } else if (cnt5 >= 3) {
          cnt5 -= 3;
        } else {
          return false;
        }
      }
    }
    return true;
  }
};
