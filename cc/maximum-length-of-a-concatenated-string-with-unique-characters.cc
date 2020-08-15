// http://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters/description/
#include "xxx.h"

class Solution {
public:
  int maxLength(vector<string> &arr) {
    vector<bitset<26>> dp{bitset<26>{}};
    int ret = 0;
    for (auto &s : arr) {
      bitset<26> cur;
      for (auto c : s) {
        cur.set(c - 'a', true);
      }
      const int n = cur.count();
      // 本身有重复
      if (n < s.size()) {
        continue;
      }
      for (int i = dp.size() - 1; i >= 0; --i) {
        auto prev = dp[i];
        // 有重叠
        if ((prev & cur).any()) {
          continue;
        }
        dp.push_back(prev | cur);
        ret = max(ret, (int)prev.count() + n);
      }
    }

    return ret;
  }
};
