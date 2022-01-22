// http://leetcode.com/problems/wiggle-subsequence/description/
#include "xxx.hpp"

class Solution {
public:
  int wiggleMaxLength(vector<int> &nums) {
    const int n = nums.size();
    if (n <= 1) {
      return n;
    }
    vector<int> reduce;
    for (int i = 1; i < n; i++) {
      if (nums[i] - nums[i - 1] > 0) {
        reduce.push_back(1);
      } else if (nums[i] - nums[i - 1] < 0) {
        reduce.push_back(-1);
      }
    }
    int ret = 1;
    for (int i = 0; i < reduce.size(); i++) {
      if (i == 0 || reduce[i] != reduce[i - 1]) {
        ret++;
      }
    }

    return ret;
  }
};
