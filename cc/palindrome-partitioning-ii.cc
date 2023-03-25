// http://leetcode.com/problems/leetcode/palindrome-partitioning-ii/description/
#include "xxx.hpp"

class Solution {
public:
  int minCut(string s) {
    int sz = s.size();
    vector<vector<int>> dp(sz, vector<int>(sz, 0));
    vector<int> min_cut(sz, 0);

    for (int j = 0; j < sz; j++) {
      // j + 1 - 1
      int cur_cut = j;
      for (int i = 0; i <= j; i++) {
        // 'aa' 'a' 'aa'
        if (s[i] == s[j] && (j - i < 2 || dp[i + 1][j - 1])) {
          dp[i][j] = 1;
          cur_cut = min((i == 0 ? 0 : min_cut[i - 1] + 1), cur_cut);
        }
      }
      min_cut[j] = cur_cut;
    }

    return min_cut[sz - 1];
  }
};
