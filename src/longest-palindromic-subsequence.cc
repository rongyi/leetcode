// http://leetcode.com/problems/longest-palindromic-subsequence/description/
#include "xxx.h"

class Solution {
public:
  //  If the two ends of a string are the same, then they must be included in
  //  the longest palindrome subsequence. Otherwise, both ends cannot be
  //  included in the longest palindrome subsequence.
  int longestPalindromeSubseq(string s) {
    const int m = s.size();
    vector<vector<int>> memo(m, vector<int>(m, 0));
    return recur(0, s.size() - 1, s, memo);
  }
  int recur(int l, int r, string &s, vector<vector<int>> &memo) {
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
      memo[l][r] = 2 + recur(l + 1, r - 1, s, memo);
      return memo[l][r];
    }
    // 否则这两个都不能用在结果上

    memo[l][r] = max(recur(l, r - 1, s, memo), recur(l + 1, r, s, memo));
    return memo[l][r];
  }
};
