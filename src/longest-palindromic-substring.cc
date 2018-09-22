// http://leetcode.com/problems/longest-palindromic-substring/description/
#include "one.h"

class Solution {
public:
  string longestPalindrome(string s) {
    const int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (i >= j) {
          // 空字符串以及长度为1的都是回文
          dp[i][j] = 1;
        }
      }
    }
    int maxlen = 1;
    int max_start = 0;

    for (int l = 1; l < n; ++l) {
      for (int i = 0; i + l < n; ++i) {
        int j = i + l;
        if (s[i] == s[j]) {
          dp[i][j] = dp[i + 1][j - 1];
          if (dp[i][j] == 1) {
            if (l + 1 > maxlen) {
              maxlen = l + 1;
              max_start = i;
            }
          }
        }
      }
    }
    return s.substr(max_start, maxlen);
  }
};

int main() {
  Solution so;
  auto ret = so.longestPalindrome("cbbd");
  cout << ret << endl;
}
