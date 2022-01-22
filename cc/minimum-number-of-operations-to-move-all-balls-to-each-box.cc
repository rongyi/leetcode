// http://leetcode.com/problems/minimum-number-of-operations-to-move-all-balls-to-each-box/description/
#include "xxx.hpp"

class Solution {
public:
  vector<int> minOperations(string boxes) {
    // 左边来一轮
    int one_count = 0;
    int cur_count = 0;
    const int n = boxes.size();
    vector<int> ret(n, 0);
    for (int i = 0; i < n; ++i) {
      ret[i] += cur_count;
      one_count += boxes[i] == '1' ? 1 : 0;
      // 右边那位算的时候直接把左边拿过加上one的个数，好好体会
      cur_count += one_count;
    }
    // reset
    one_count = 0;
    cur_count = 0;
    for (int i = n - 1; i >= 0; --i) {
      ret[i] += cur_count;
      one_count += boxes[i] == '1' ? 1 : 0;
      cur_count += one_count;
    }

    return ret;
  }
};
