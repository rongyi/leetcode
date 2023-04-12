// http://leetcode.com/problems/rotate-array/description/
#include "xxx.hpp"

class Solution {
public:
  void rotate(vector<int> &nums, int k) {
    int sz = nums.size();
    k %= sz;
    reverse(nums.begin(), nums.end());
    reverse(nums.begin(), nums.begin() + k);
    reverse(nums.begin() + k, nums.end());
  }
};
