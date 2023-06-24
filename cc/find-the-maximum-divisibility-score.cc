// https://leetcode.com/problems/find-the-maximum-divisibility-score/
#include "xxx.hpp"

class Solution {
public:
  int maxDivScore(vector<int> &nums, vector<int> &divisors) {
    set<int> uniq(divisors.begin(), divisors.end());
    int max_divisor = -1;
    int num = -1;
    for (auto &k : uniq) {
      int d = 0;
      for (auto &num : nums) {
        if (num % k == 0) {
          d++;
        }
      }
      if (d > max_divisor) {
        max_divisor = d;
        num = k;
      }
    }
    return num;
  }
};
