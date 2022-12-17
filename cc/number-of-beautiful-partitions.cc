// https://leetcode.com/problems/number-of-beautiful-partitions/
#include "xxx.hpp"

class Solution {
public:
  int beautifulPartitions(string s, int k, int minLength) {
    return dfs(s, 0, k, minLength);
  }

private:
  bool isPrime(char c) { return c == '2' || c == '3' || c == '5' || c == '7'; }
  int dfs(string &s, int i, int k, int len) {
    if (k == 0) {
      return (i == s.size());
    }
    // not enough lenth or can not cut
    if (i + len * k > s.size() || !isPrime(s[i])) {
      return 0;
    }
    if (dp_[i][k] == 0) {
      dp_[i][k] = 1;
      for (int j = i + len - 1; j < s.size(); ++j) {
        if (!isPrime(s[j])) {
          dp_[i][k] =
              (dp_[i][k] + dfs(s, j + 1, k - 1, len)) % (long long)(1e9 + 7);
        }
      }
    }
    return dp_[i][k] - 1;
  }

private:
  long long dp_[1001][1000] = {};
};
