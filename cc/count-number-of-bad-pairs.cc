// https://leetcode.com/problems/count-number-of-bad-pairs/
#include "xxx.hpp"

class Solution {
public:
  long long countBadPairs(vector<int> &nums) {
    long long ret = 0;
    map<int, int> diff;
    for (int i = 0; i < nums.size(); ++i) {
      ret += i - diff[nums[i] - i];
      diff[nums[i] - i]++;
    }

    return ret;
  }
};
