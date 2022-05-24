// https://leetcode.com/problems/largest-combination-with-bitwise-and-greater-than-zero/
#include "xxx.hpp"

class Solution {
public:
  int largestCombination(vector<int> &candidates) {
    // count each pos occurance for all integers
    vector<int> mask(31, 0);
    for (auto cur : candidates) {
      for (int i = 0; i < 31; ++i) {
        mask[i] += (cur & (1 << i)) != 0;
      }
    }
    // then the max_element of some mask is the
    // number of longest and

    return *max_element(mask.begin(), mask.end());
  }
};
