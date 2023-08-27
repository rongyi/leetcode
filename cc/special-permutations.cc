// https://leetcode.com/problems/special-permutations/
#include "xxx.hpp"

class Solution {
public:
  int specialPerm(vector<int> &nums) {
    memset(dp_, -1, sizeof(dp_));
    return dfs(0, 0, nums);
  }

private:
  // last choice index is cur
  int dfs(int cur, int mask, vector<int> &nums) {
    if (mask == (1 << nums.size()) - 1) {
      return 1;
    }
    if (dp_[cur][mask] == -1) {
      dp_[cur][mask] = 0;

      for (int i = 0; i < nums.size(); i++) {
        // already selected
        if (((1 << i) & mask) != 0) {
          continue;
        }
        // check mod
        if (mask == 0 || (nums[i] % nums[cur] == 0) ||
            (nums[cur] % nums[i] == 0)) {
          dp_[cur][mask] =
              (dp_[cur][mask] + dfs(i, mask | (1 << i), nums)) % (int)(1e9 + 7);
        }
      }
    }

    return dp_[cur][mask];
  }

private:
  int dp_[14][1 << 14];
};
