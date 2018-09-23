// http://leetcode.com/problems/3sum/description/
#include "one.h"
class Solution {
public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    const int n = nums.size();
    vector<vector<int>> ret;
    if (n < 3) {
      return ret;
    }
    sort(nums.begin(), nums.end());
    auto last = n - 1;
    const int target = 0;

    for (int i = 0; i < last - 1; ++i) {
      if (i > 0 && nums[i] == nums[i - 1]) {
        continue;
      }
      auto j = i + 1;
      auto k = last;
      while (j < k) {
        auto cur = nums[i] + nums[j] + nums[k];
        if (cur < target) {
          ++j;

          while (nums[j] == nums[j - 1] && j < k) {
            ++j;
          }
        } else if ( cur > target) {
          --k;
          while (nums[k] == nums[k + 1] && j < k) {
            --k;
          }
        } else {
          ret.push_back({nums[i], nums[j], nums[k]});
          ++j;
          --k;
          while (nums[j] == nums[j - 1] && j < k) {
            ++j;
          }
          while (nums[k] == nums[k + 1] && j < k) {
            --k;
          }
        }
      }
    }


    return ret;
  }
};
