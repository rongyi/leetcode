// http://leetcode.com/problems/remove-element/description/
#include "xxx.hpp"

class Solution {
public:
  int removeElement(vector<int> &nums, int val) {
    int sz = nums.size();
    // delete index
    int di = 0;
    for (int i = 0; i < sz; ++i) {
      if (nums[i] != val) {
        nums[di++] = nums[i];
      }
    }
    return di;
  }
};
