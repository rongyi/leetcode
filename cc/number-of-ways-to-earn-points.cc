// https://leetcode.com/problems/number-of-ways-to-earn-points/
#include "xxx.hpp"

class Solution {
public:
  int waysToReachTarget(int target, vector<vector<int>> &types) {
    dp_.resize(types.size() + 1, vector<int>(target + 1, -1));

    return dfs(0, types, target);
  }

private:
  long long dfs(int cur_idx, vector<vector<int>> &types, int target) {
    if (target == 0) {
      return 1;
    }
    if (cur_idx == types.size()) {
      return target == 0;
    }
    if (dp_[cur_idx][target] != -1) {
      return dp_[cur_idx][target] % mod_;
    }

    long long ret = 0;
    // use current from 0 to count
    // and check lest score is target - current_used * current_score
    // and make sure target is >= 0
    for (int i = 0;
         i <= types[cur_idx][0] && (target - types[cur_idx][1] * i >= 0); i++) {
      ret += dfs(cur_idx + 1, types, target - types[cur_idx][1] * i);
    }

    return dp_[cur_idx][target] = ret % mod_;
  }

private:
  vector<vector<int>> dp_;
  int mod_ = 1e9 + 7;
};
