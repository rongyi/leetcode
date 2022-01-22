// https://leetcode.com/problems/number-of-pairs-of-strings-with-concatenation-equal-to-target/
#include "xxx.hpp"

class Solution {
public:
  int numOfPairs(vector<string> &nums, string target) {
    int sz = nums.size();
    int ret = 0;
    for (int i = 0; i < sz; ++i) {
      for (int j = 0; j < sz; ++j) {
        if (i != j) {
          if (nums[i].size() + nums[j].size() == target.size() &&
              nums[i] + nums[j] == target) {
            ret += 1;
          }
        }
      }
    }

    return ret;
  }
};
