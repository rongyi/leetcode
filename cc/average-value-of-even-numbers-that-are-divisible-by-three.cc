// https://leetcode.com/problems/average-value-of-even-numbers-that-are-divisible-by-three/
#include "xxx.hpp"

class Solution {
public:
  int averageValue(vector<int> &nums) {
    long long sum = 0;
    int cnt = 0;
    for (auto &num : nums) {
      if ((num & 1) == 0 && num % 3 == 0) {
        cnt += 1;
        sum += num;
      }
    }

    if (cnt == 0) {
      return 0;
    }
    return sum / cnt;
  }
};
