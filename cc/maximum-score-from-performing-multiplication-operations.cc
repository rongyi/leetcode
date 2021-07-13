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
  // Three States define the state of Memoization

  // 1. index of multiplication array (a)
  // 2. start index of nums array (l)
  // 3. end index of nums array(r)
  // But if We know the start index(l) and end(r) index we can easily get index
  // of muliplication array a=l+(n-1-r)
  // 也即用掉了多少，那么乘法的idx就在哪里

  // so number of states reduced to two, But we cannot make a 10^5 X 10^5 arrray
  // to store result of (l,r) but one thing to be notice that number of elements
  // in muliplication array if 10^3 so instead of using l and r as states we can
  // use distance of l from starting and distance of r from end as the states
  // 够刁钻

  // as m<=10^3 so distance will be less than 10^3

  // i=l and j=n-1-r
  // i and j are distance from the start and end respectively and the new states
  // of the dp array.
  int dp_[1001][1001];
};
