// http://leetcode.com/problems/leetcode/4sum/description/
#include "xxx.hpp"

class Solution {
public:
  vector<vector<int>> fourSum(vector<int> &nums, int target) {
    vector<vector<int>> ret;
    const int n = nums.size();
    // noway!
    if (n < 4) {
      return ret;
    }
    sort(nums.begin(), nums.end());
    for (int i = 0; i < n - 3; ++i) {
      if (i > 0 && nums[i] == nums[i - 1]) {
        continue;
      }
      int j = i + 1;
      for (; j < n - 2; ++j) {
        if (j > i + 1 && nums[j] == nums[j - 1]) {
          continue;
        }
        auto left = j + 1;
        auto right = n - 1;
        while (left < right) {
          auto sum = nums[i] + nums[j] + nums[left] + nums[right];
          if (sum == target) {
            ret.push_back({{nums[i], nums[j], nums[left], nums[right]}});
            left++;
            right--;
            while (left < right && nums[left] == nums[left - 1]) {
              left++;
            }
            while (left < right && nums[right] == nums[right + 1]) {
              right--;
            }
          } else if (sum > target) {
            right--;
          } else {
            left++;
          }
        } // end left right while
      } // end for j
    } // end for i

    return ret;
  }
};
