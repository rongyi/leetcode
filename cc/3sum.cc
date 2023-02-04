// http://leetcode.com/problems/3sum/description/
#include "xxx.hpp"
class Solution {
public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    int sz = nums.size();

    vector<vector<int>> ret;
    for (int i = 0; i < sz; ++i) {
      if (i > 0 && nums[i] == nums[i - 1]) {
        continue;
      }
      int j = i + 1;
      int k = sz - 1;
      while (j < k) {
        int cur = nums[i] + nums[j] + nums[k];
        if (cur == 0) {
          ret.push_back({nums[i], nums[j], nums[k]});
          while (j < k && nums[j] == ret.back()[1]) {
            j++;
          }
          while (j < k && nums[k] == ret.back()[2]) {
            k--;
          }
        } else if (cur > 0) {
          k--;
        } else {
          j++;
        }
      }
    }

    return ret;
  }
};
