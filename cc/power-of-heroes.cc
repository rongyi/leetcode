// https://leetcode.com/problems/power-of-heroes/
#include "xxx.hpp"

class Solution {
public:
  // https://leetcode.com/problems/power-of-heroes/solutions/3520233/c-java-python-sort-and-enumerate-each-maximum-value/
  int sumOfPower(vector<int> &nums) {
    long long ret = 0;
    long long s = 0;
    long long mod = 1e9 + 7;
    sort(nums.begin(), nums.end());
    for (auto x : nums) {
      ret = (ret + (s + x) * x % mod * x % mod) % mod;

      s = (s * 2 + x) % mod;
    }

    return ret;
  }
};
