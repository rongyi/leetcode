// http://www.lintcode.com/zh-cn/problem/leetcode/permutations-ii
#include "xxx.hpp"

class Solution {
public:
  vector<vector<int>> permuteUnique(vector<int> &nums) {
    vector<vector<int>> ret;
    sort(nums.begin(), nums.end());
    recur(nums, 0, ret);

    return ret;
  }

private:
  void recur(vector<int> nums, int pos, vector<vector<int>> &ret) {
    if (pos == nums.size()) {
      ret.push_back(nums);
      return;
    }
    for (unsigned i = pos; i < nums.size(); ++i) {
      if (i > pos && nums[i] == nums[pos]) {
        continue;
      }
      swap(nums[pos], nums[i]);
      recur(nums, pos + 1, ret);
    }
  }
};
