// http://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/description/
#include "xxx.h"

class Solution {
public:
  int minInsertions(string s) { return s.size() - longestPalindromPrefix(s); }

private:
  int longestPalindromPrefix(string &s) {
    const int n = s.size();
    vector<vector<int>> memo(n, vector<int>(n, 0));
    return recur(s, 0, n - 1, memo);
  }

  // dfs version
  int recur(const string &s, int l, int r, vector<vector<int>> &memo) {
    if (l == r) {
      return 1;
    }
    if (l > r) {
      return 0;
    }
    if (memo[l][r]) {
      return memo[l][r];
    }
    if (s[l] == s[r]) {
      memo[l][r] = 2 + recur(s, l + 1, r - 1, memo);
      return memo[l][r];
    }
    memo[l][r] = max(recur(s, l + 1, r, memo), recur(s, l, r - 1, memo));
    return memo[l][r];
  }
};
