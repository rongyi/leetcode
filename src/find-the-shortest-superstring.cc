// http://leetcode.com/problems/find-the-shortest-superstring/description/
#include "xxx.h"

class Solution {
public:
  string shortestSuperstring(vector<string> &A) {
    n_ = A.size();
    overlap_ = vector<vector<int>>(n_, vector<int>(n_, 0));
    buildOverlap(A);

    // dp[i][j]
    // i ==> 访问过的node的mask， 每一个node占一位
    // j ==> 表示最后一个访问元素是node j
    vector<vector<string>> dp(1 << n_, vector<string>(n_, ""));
    for (int i = 0; i < n_; i++) {
      dp[1 << i][i] += A[i];
    }
    for (int mask = 1; mask < (1 << n_); ++mask) {
      for (int j = 0; j < n_; j++) {
        if (!(mask & (1 << j))) {
          continue;
        }
        for (int i = 0; i < n_; i++) {
          if (i != j && (mask & (1 << i)) > 0) {
            string tmp = dp[mask ^ (1 << j)][i] + A[j].substr(overlap_[i][j]);
            if (dp[mask][j].empty() || tmp.size() < dp[mask][j].size()) {
              dp[mask][j] = tmp;
            }
          }
        }
      }
    }
    int last = (1 << n_) - 1;
    string ret = dp[last][0];
    for (int i = 1; i < n_; i++) {
      if (dp[last][i].size() < ret.size()) {
        ret = dp[last][i];
      }
    }
    return ret;
  }

public:
  void buildOverlap(vector<string> &strs) {
    for (int i = 0; i < n_; i++) {
      for (int j = 0; j < n_; j++) {
        if (i == j) {
          continue;
        }
        string &from = strs[i];
        string &to = strs[j];

        for (int k = min(from.size(), to.size()); k > 0; k--) {
          // A="catg" B= "atgcatc" ==> atg overlap
          // so (A, B) overlap is 3
          string to_sub = to.substr(0, k);
          string from_sub = from.substr(from.size() - k);
          if (to_sub == from_sub) {
            overlap_[i][j] = k;
            break;
          }
        }
      }
    }
  }

private:
  int n_;
  vector<vector<int>> overlap_;

  unordered_map<string, string> cache_;
};
