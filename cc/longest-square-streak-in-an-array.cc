// https://leetcode.com/problems/longest-square-streak-in-an-array/
#include "xxx.hpp"

class Solution {
public:
  int longestSquareStreak(vector<int> &nums) {
    set<long long> uniq(nums.begin(), nums.end());
    int ret = -1;
    for (auto num : nums) {
      ret = max(ret, lss(num, uniq));
    }
    return ret;
  }

private:
  int lss(long long num, set<long long> &uniq) {
    int len = 0;
    while (uniq.count(num)) {
      num *= num;
      len++;
    }
    if (len < 2) {
      return -1;
    }
    return len;
  }
};
