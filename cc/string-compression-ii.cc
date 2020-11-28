// http://leetcode.com/problems/string-compression-ii/description/
#include "xxx.h"

class Solution {
public:
  // https://leetcode.com/problems/string-compression-ii/discuss/756022/C%2B%2B-Top-Down-DP-with-explanation-64ms-short-and-clear
  int getLengthOfOptimalCompression(string s, int k) {
    const int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));

    return recur(s, dp, 0, k);
  }

private:
  int recur(string &s, vector<vector<int>> &dp, int left, int k) {
    if (k < 0) {
      return s.size();
    }
    if (left >= s.size() || s.size() - left <= k) {
      return 0;
    }
    int &ret = dp[left][k];
    if (ret != -1) {
      return ret;
    }
    ret = s.size();

    vector<int> cnt(26, 0);
    for (int j = left, most = 0; j < s.size(); ++j) {
      most = max(most, ++cnt[s[j] - 'a']);
      ret = min(ret, 1 + digitcount(most) +
                         // 减去使用掉的整个substring减去most就是使用的
                         recur(s, dp, j + 1, k - (j - left + 1 - most)));
    }

    return ret;
  }
  int digitcount(int x) {
    if (x == 1) {
      return 0;
    }
    if (x < 10) {
      return 1;
    }
    if (x < 100) {
      return 2;
    }

    return 3;
  }
};
