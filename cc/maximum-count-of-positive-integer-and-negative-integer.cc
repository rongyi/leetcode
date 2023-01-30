// https://leetcode.com/problems/maximum-count-of-positive-integer-and-negative-integer/
#include "xxx.hpp"

class Solution {
public:
  int maximumCount(vector<int> &nums) {
    int i = 0;
    int sz = nums.size();
    int neg_cnt = 0;

    for (; i < sz; ++i) {
      if (nums[i] < 0) {
        neg_cnt++;
      } else if (nums[i] > 0) {
        break;
      }
    }

    return max(neg_cnt, sz - i);
  }
};
