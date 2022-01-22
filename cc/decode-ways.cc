// http://leetcode.com/problems/decode-ways/description/
#include "xxx.hpp"

class Solution {
public:
  int numDecodings(string s) {
    if (s.empty() || s[0] < '1' || s[0] > '9') {
      return 0;
    }
    // dp[i] 表示有i个数字的可能有多少个？
    vector<int> dp(s.size() + 1, 0);
    // 空字符这里定为有一种
    dp[0] = 1;
    // 一个字符也只有一种，当然前提是不为0，这个前提前面判断了
    dp[1] = 1;

    for (int i = 1; i < s.size(); ++i) {
      if (!isdigit(s[i])) {
        return 0;
      }
      int cur = (s[i - 1] - '0') * 10 + (s[i] - '0');
      // 可以凑成两个
      if (cur > 9 && cur <= 26) {
        dp[i + 1] += dp[i - 1];
      }
      // 可以以1个拼接
      if (s[i] != '0') {
        dp[i + 1] += dp[i];
      }
      if (dp[i + 1] == 0) {
        return 0;
      }
    }
    return dp[s.size()];
  }
};
