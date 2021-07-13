// http://leetcode.com/problems/maximum-score-from-performing-multiplication-operations/description/
#include "xxx.h"

class Solution {
public:
  int maximumScore(vector<int> &nums, vector<int> &multipliers) {
    const int n = nums.size();
    memset(dp_, -1, sizeof(dp_));

    return dfs(nums, multipliers, 0, n - 1, 0);
  }

private:
  int dfs(vector<int> &nums, vector<int> &mutis, int l, int r, int midx) {
    if (midx >= mutis.size()) {
      return 0;
    }
    if (l > r) {
      return 0;
    }
    // 到左右边界节点的距离
    int i = l;
    int j = nums.size() - 1 - r;
    if (dp_[i][j] != -1) {
      return dp_[i][j];
    }
    auto val1 = nums[l] * mutis[midx] + dfs(nums, mutis, l + 1, r, midx + 1);
    auto val2 = nums[r] * mutis[midx] + dfs(nums, mutis, l, r - 1, midx + 1);
    dp_[i][j] = max(val1, val2);

    return dp_[i][j];
  }

private:
  int dp_[1001][1001];
};
