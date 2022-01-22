// http://leetcode.com/problems/longest-consecutive-sequence/description/
#include "xxx.hpp"

class Solution {
public:
  int longestConsecutive(vector<int> &nums) {
    int ret = 0;
    unordered_set<int> dict;
    for (auto i : nums) {
      dict.insert(i);
    }

    for (int i = 0; i < nums.size(); ++i) {
      int cur_range = 0;
      if (dict.find(nums[i]) != dict.end()) {
        cur_range++;
        dict.erase(nums[i]);
      }
      for (int j = nums[i] + 1; dict.find(j) != dict.end(); ++j) {
        cur_range++;
        dict.erase(j);
      }
      for (int j = nums[i] - 1; dict.find(j) != dict.end(); --j) {
        cur_range++;
        dict.erase(j);
      }
      ret = max(cur_range, ret);
    }

    return ret;
  }
};
