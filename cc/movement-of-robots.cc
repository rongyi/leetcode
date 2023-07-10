// https://leetcode.com/problems/movement-of-robots/
#include "xxx.hpp"

class Solution {
public:
  int sumDistance(vector<int> &nums, string s, int d) {
    int sz = nums.size();
    for (int i = 0; i < sz; i++) {
      if (s[i] == 'L') {
        nums[i] -= d;
      } else {
        nums[i] += d;
      }
    }
    long long prefix = 0;
    long long ret = 0;
    int mod = 1e9 + 7;

    sort(nums.begin(), nums.end());

    for (long long i = 0; i < sz; i++) {
      ret = (ret + i * nums[i] - prefix) % mod;
      prefix += nums[i];
    }

    return ret;
  }
};
