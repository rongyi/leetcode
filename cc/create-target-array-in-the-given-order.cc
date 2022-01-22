// http://leetcode.com/problems/create-target-array-in-the-given-order/description/
#include "xxx.hpp"

class Solution {
public:
  vector<int> createTargetArray(vector<int> &nums, vector<int> &index) {
    vector<int> ret;
    const int n = nums.size();
    for (int i = 0; i < n; ++i) {
      ret.insert(ret.begin() + index[i], nums[i]);
    }

    return ret;
  }
};
