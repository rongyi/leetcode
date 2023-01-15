// https://leetcode.com/problems/distinct-prime-factors-of-product-of-array/
#include "xxx.hpp"

class Solution {
public:
  int distinctPrimeFactors(vector<int> &nums) {
    set<int> fs;
    auto collectFactor = [&](int num) {
      for (int i = 2, cp = num; i <= num && cp > 1; i++) {
        bool have = false;
        while ((cp % i) == 0) {
          cp /= i;
          have = true;
        }
        if (have) {
          fs.insert(i);
        }
      }
    };

    for (auto &num: nums) {
      collectFactor(num);
    }

    return fs.size();
  }
};
