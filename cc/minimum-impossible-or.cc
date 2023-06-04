// https://leetcode.com/problems/minimum-impossible-or/
#include "xxx.hpp"

class Solution {
public:
  int minImpossibleOR(vector<int> &nums) {
    set<int> uniq(nums.begin(), nums.end());
    int ret = 1;
    while (uniq.count(ret)) {
      ret *= 2;
    }

    return ret;
  }
};
