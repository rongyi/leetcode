// http://leetcode.com/problems/xor-queries-of-a-subarray/description/
#include "xxx.h"

class Solution {
public:
  vector<int> xorQueries(vector<int> &arr, vector<vector<int>> &queries) {
    const int n = arr.size();
    // every bit sum
    // prefixsum的思路用在位上
    vector<vector<int>> dp(n + 1, vector<int>(31, 0));
    for (int i = 0; i < 31; i++) {
      for (int j = 0; j < n; j++) {
        dp[j + 1][i] = dp[j][i];

        if ((arr[j] >> i) & 1) {
          dp[j + 1][i] += 1;
        }
      }
    }
    vector<int> ret;
    for (auto &q : queries) {
      auto start = q[0];
      auto end = q[1];
      int cur = 0;
      for (int i = 0; i < 31; i++) {
        int cur_zero = dp[end + 1][i] - dp[start][i];
        if (cur_zero & 1) {
          cur |= (1 << i);
        }
      }
      ret.push_back(cur);
    }

    return ret;
  }
};
