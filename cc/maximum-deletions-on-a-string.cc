// https://leetcode.com/problems/maximum-deletions-on-a-string/
#include "xxx.hpp"

class Solution {
public:
  int deleteString(string s) {
    int sz = s.size();
    vector<vector<int>> lcs(sz + 1, vector<int>(sz + 1, 0));

    vector<int> dp(sz, 1);
    for (int i = sz - 1; i >= 0; --i) {
      for (int j = i + 1; j < sz; ++j) {
        if (s[i] == s[j]) {
          lcs[i][j] = lcs[i + 1][j + 1] + 1;
        }
        if (lcs[i][j] >= j - i) {
          dp[i] = max(dp[i], dp[j] + 1);
        }
      }
    }

    return dp[0];
  }
};

int main(int argc, char *argv[]) {
  Solution so;
  so.deleteString("aaaa");
  return 0;
}
