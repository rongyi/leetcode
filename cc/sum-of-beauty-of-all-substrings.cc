// http://leetcode.com/problems/sum-of-beauty-of-all-substrings/description/
#include "xxx.hpp"

class Solution {
public:
  // 没想到是暴力的解法
  int beautySum(string s) {
    int ret = 0;
    const int n = s.size();
    for (int i = 0; i < n; ++i) {
      vector<int> count(26, 0);
      int max_freq = 0;
      int min_freq = 0;
      for (int j = i; j < n; ++j) {
        int cur_idx = s[j] - 'a';
        max_freq = max(max_freq, ++count[cur_idx]);
        if (min_freq >= count[cur_idx] - 1) {
          min_freq = count[cur_idx];
          for (int k = 0; k < 26; ++k) {
            min_freq = min(min_freq, count[k] == 0 ? numeric_limits<int>::max()
                                                   : count[k]);
          }
        }
        ret += (max_freq - min_freq);
      }
    }

    return ret;
  }
};
