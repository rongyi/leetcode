// https://leetcode.com/problems/make-array-zero-by-subtracting-equal-amounts/
#include "xxx.hpp"

class Solution {
public:
  int minimumOperations(vector<int> &nums) {
    set<int> uniq(nums.begin(), nums.end());
    vector<int> sorted_uniq(uniq.begin(), uniq.end());
    int gap_prefix = 0;

    int ret = 0;
    for (int i = 0; i < sorted_uniq.size(); ++i) {
      int num = sorted_uniq[i]- gap_prefix;
      if (num > 0) {
        gap_prefix += num;
        ret++;
      }
    }

    return ret;
  }
};
