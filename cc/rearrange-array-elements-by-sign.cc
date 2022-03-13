// https://leetcode.com/problems/rearrange-array-elements-by-sign/
#include "xxx.hpp"

class Solution {
public:
  vector<int> rearrangeArray(vector<int> &nums) {
    int sz = nums.size();
    vector<int> pos(sz / 2, 0);
    vector<int> neg(sz / 2, 0);
    int i = 0;
    int j = 0;
    for (auto &num : nums) {
      if (num > 0) {
        pos[i++] = num;
      } else {
        neg[j++] = num;
      }
    }
    i = 0;
    j = 0;
    for (int k = 0; k < sz; k += 2) {
      nums[k] = pos[i++];
      nums[k + 1] = neg[j++];
    }

    return nums;
  }
};
