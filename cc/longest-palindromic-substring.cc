// http://leetcode.com/problems/longest-palindromic-substring/description/
#include "xxx.hpp"

class Solution {
public:
  string longestPalindrome(string s) {
    int sz = s.size();
    // dp[i][j] is s[i..=j] palindromic?
    vector<vector<int>> dp(sz, vector<int>(sz, 0));
    for (int i = 0; i < sz; ++i) {
      for (int j = 0; j <= i; ++j) {
        // empty or s[i]
        dp[i][j] = 1;
      }
    }
    int max_start = 0;
    int max_len = 1;
    for (int l = 1; l < sz; ++l) {
      for (int i = 0; i + l < sz; ++i) {
        int j = i + l;
        if (s[i] == s[j]) {
          dp[i][j] = dp[i + 1][j - 1];
          if (dp[i][j] == 1) {
            int val = l + 1;
            if (val > max_len) {
              max_len = val;
              max_start = i;
            }
          }
        }
      }
    }
    return s.substr(max_start, max_len);
  }
};

int main() {
  Solution so;
  auto ret = so.longestPalindrome("cbbd");
  cout << ret << endl;
}
