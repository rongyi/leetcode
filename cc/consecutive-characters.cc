// http://leetcode.com/problems/consecutive-characters/description/
#include "xxx.h"

class Solution {
public:
  int maxPower(string s) {
    int ret = numeric_limits<int>::min();
    char cur = s[0];
    int cur_sum = 1;
    for (int i = 1; i < s.size(); ++i) {
      if (s[i] == cur) {
        cur_sum++;
      } else {
        ret = max(ret, cur_sum);

        cur = s[i];
        cur_sum = 1;
      }
    }

    // 最后一个和它前面的字符相等
    ret = max(ret, cur_sum);

    return ret;
  }
};
