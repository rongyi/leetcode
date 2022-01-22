// http://leetcode.com/problems/delete-operation-for-two-strings/description/
#include "xxx.hpp"

class Solution {
public:
  int minDistance(string word1, string word2) {
    // 理解错了，不是找公共子串，然后算各自的delta
    // const int m = word1.size();
    // const int n = word2.size();
    // vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    // int lcs = 0;
    // for (int i = 1; i <= m; i++) {
    //   for (int j = 1; j <= n; j++) {
    //     if (word1[i - 1] == word2[j - 1]) {
    //       dp[i][j] = dp[i - 1][j - 1] + 1;
    //       lcs = max(lcs, dp[i][j]);
    //     } else {
    //       dp[i][j] = 0;
    //     }
    //   }
    // }
    // // cout << lcs << endl;
    // return (m - lcs) + (n - lcs);

    // 也不对，order matters
    // const int m = word1.size();
    // const int n = word2.size();
    // vector<int> c1(26, 0);
    // vector<int> c2(26, 0);
    // for (auto c : word1) {
    //   c1[c - 'a']++;
    // }
    // for (auto c : word2) {
    //   c2[c - 'a']++;
    // }
    // int count = 0;
    // for (int i = 0; i < 26; i++) {
    //   count += min(c1[i], c2[i]);
    // }
    // return (m - count) + (n - count);

    // 应该是 subsequence
    const int m = word1.size();
    const int n = word2.size();
    // probelm: lcs(s1, s2) i.e. longest common subsequence
    // s1 = sub1 + e1 (e1 is the last char)
    // s2 = sub2 + e2 (e2 is the last char)
    // when e1 == e2 ==> problem can be recursived to lcs(sub1, sub2) + e1
    // else when e1 != e2 ==> 1. or 2. or 3. which 1. 2. and 3. is below
    // 1. lcs(sub1, s2)
    // 2. lcs(s1, sub2)
    // 3. lcs(sub1, sub2)
    // when come to the length we can just ignore lcs(sub1, sub2)
    // because lcs(sub1, sub2) can never be larger than(max(lcs(sub1, s2), lcs(s1, sub2)))
    // (using less char to generate longer subsequence? ==> no way)
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= m; i++) {
      for (int j = 1; j <= n; j++) {
        if (word1[i - 1] == word2[j - 1]) {
          dp[i][j] = dp[i - 1][j - 1] + 1;
        } else {
          dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
      }
    }

    return (m - dp[m][n]) + (n - dp[m][n]);
  }
};
