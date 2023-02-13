// http://leetcode.com/problems/permutations/description/
#include "xxx.hpp"

class Solution {
public:
  vector<vector<int>> permute(vector<int> &nums) {
    vector<vector<int>> ret;
    recur(nums, 0, ret);

    return ret;
  }

private:
  // there's picture at this link show the process very well
  // https://stackoverflow.com/questions/7537791/understanding-recursion-to-generate-permutations
  void recur(vector<int> &nums, int pos, vector<vector<int>> &ret) {
    if (pos >= nums.size()) {
      ret.push_back(nums);
      return;
    }
    for (int i = pos; i < nums.size(); i++) {
      swap(nums[pos], nums[i]);
      recur(nums, pos + 1, ret);
      swap(nums[pos], nums[i]);
    }
  }
};
