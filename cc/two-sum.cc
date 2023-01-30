// http://leetcode.com/problems/two-sum/description/
#include "xxx.hpp"
class Solution {
public:
  vector<int> twoSum(vector<int> &nums, int target) {
    // {val, idx}
    vector<pair<int, int>> num_idx;
    int sz = nums.size();
    for (int i = 0; i < sz; ++i) {
      num_idx.push_back({nums[i], i});
    }
    sort(num_idx.begin(), num_idx.end());
    int i = 0;
    int j = sz - 1;
    while (i < j) {
      auto cur = num_idx[i].first + num_idx[j].first;
      if (cur == target) {
        return {num_idx[i].second, num_idx[j].second};
      } else if (cur > target) {
        j--;
      } else {
        i++;
      }
    }

    return {};
  }
};
