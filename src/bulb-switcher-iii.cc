// http://leetcode.com/problems/bulb-switcher-iii/description/
#include "xxx.h"

class Solution {
public:
  int numTimesAllBlue(vector<int> &light) {
    vector<int> prefix_sum(light.size() + 1, 0);
    for (int i = 0; i < light.size(); ++i) {
      prefix_sum[i + 1] = prefix_sum[i] + (i + 1);
    }
    int cur_sum = 0;
    int ret = 0;

    // 全部点亮，和与预期的prefixsum肯定相同
    for (int i = 0; i < light.size(); ++i) {
      cur_sum += light[i];
      if (cur_sum == prefix_sum[i + 1]) {
        ++ret;
      }
    }
    return ret;
  }
};
