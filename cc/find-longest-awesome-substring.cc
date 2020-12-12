// http://leetcode.com/problems/find-longest-awesome-substring/description/
#include "xxx.h"

class Solution {
public:
  int longestAwesome(string s) {
    // mask妙用
    // 1. 为什么1024 bit mask的所有可能，字符有十个，所有可能组合的值域
    // from 00000 00000 ==> 11111 11111，标记的是最近的出现这个mask值
    // 的大小
    vector<int> dp(1024, s.size());
    dp[0] = -1;
    int ret = 0;
    int mask = 0;
    for (int i = 0; i < s.size(); ++i) {
      mask ^= 1 << (s[i] - '0');
      ret = max(ret, i - dp[mask]);

      // 差一位的情况
      for (int j = 0; j < 10; ++j) {
        ret = max(ret, i - dp[mask ^ (1 << j)]);
      }
      dp[mask] = min(dp[mask], i);
    }

    return ret;
  }
};
