// http://leetcode.com/problems/shortest-common-supersequence/description/
#include "xxx.hpp"

class Solution {
public:
  string shortestCommonSupersequence(string str1, string str2) {
    int i = 0;
    int j = 0;
    string ret{};

    for (auto c : lcs(str1, str2)) {
      while (str1[i] != c) {
        ret.push_back(str1[i++]);
      }
      while (str2[j] != c) {
        ret.push_back(str2[j++]);
      }

      ret.push_back(c);
      i++;
      j++;
    }

    return ret + str1.substr(i) + str2.substr(j);
  }

private:
  string lcs(string &A, string &B) {
    const int m = A.size();
    const int n = B.size();

    vector<vector<string>> dp(m + 1, vector<string>(n + 1, ""));

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (A[i] == B[j]) {
          dp[i + 1][j + 1] = dp[i][j] + A[i];
        } else {
          dp[i + 1][j + 1] = dp[i + 1][j].size() > dp[i][j + 1].size()
                                 ? dp[i + 1][j]
                                 : dp[i][j + 1];
        }
      }
    }

    return dp[m][n];
  }
};
