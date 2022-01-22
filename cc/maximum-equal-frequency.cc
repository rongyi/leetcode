// http://leetcode.com/problems/maximum-equal-frequency/description/
#include "xxx.hpp"

class Solution {
public:
  int maxEqualFreq(vector<int> &nums) {
    int ret = 0;
    unordered_map<int, int> count;
    unordered_map<int, int> freq;
    for (int i = 0; i < nums.size(); ++i) {
      ++count[nums[i]];
      auto cur_freq = count[nums[i]];
      ++freq[cur_freq];

      int cur_total = cur_freq * freq[cur_freq];
      // 1 1 2 2 4
      //       i
      if (cur_total == (i + 1) && i < nums.size() - 1) {
        ret = max(ret, i + 2);
      } else if (cur_total == i /* i + 1 - 1*/) {
        // 1 1 1 2 2 4
        //         i
        ret = max(ret, i + 1);
      }
    }

    return ret;
  }
};
