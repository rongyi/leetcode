// http://leetcode.com/problems/distinct-subsequences-ii/description/
#include "xxx.hpp"

class Solution {
public:
  int distinctSubseqII(string s) {
    const int mod = pow(10, 9) + 7;
    const int n = s.size();
    // 包含自己
    vector<int> dp(n, 1);
    int ret = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < i; j++) {
        if (s[j] != s[i]) {
          dp[i] += dp[j];
          dp[i] %= mod;
        }
      }

      ret += dp[i];
      ret %= mod;
    }
    return ret;
  }
};

int main() {
  Solution so;

}
