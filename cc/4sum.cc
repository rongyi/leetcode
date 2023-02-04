// http://leetcode.com/problems/leetcode/4sum/description/
#include "xxx.hpp"

class Solution {
public:
  vector<vector<int>> fourSum(vector<int> &nums, int target) {
    int sz = nums.size();
    if (sz < 4) {
      return {};
    }
    vector<vector<int>> ret;
    sort(nums.begin(), nums.end());

    for (int i = 0; i < sz - 3; i++) {
      if (i > 0 && nums[i] == nums[i - 1]) {
        continue;
      }
      for (int j = i + 1; j < sz - 2; j++) {
        if (j > i + 1 && nums[j] == nums[j - 1]) {
          continue;
        }
        int l = j + 1;
        int r = sz - 1;
        while (l < r) {
          long long sum = (long long)nums[i] + nums[j] + nums[l] + nums[r];
          if (sum < target) {
            l++;
          } else if (sum > target) {
            r--;
          } else {
            ret.push_back({nums[i], nums[j], nums[l], nums[r]});
            while (l < r && nums[l] == ret.back()[2]) {
              l++;
            }
            while (l < r && nums[r] == ret.back()[3]) {
              r--;
            }
          }
        }
      }
    }

    return ret;
  }
};
