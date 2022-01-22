// http://leetcode.com/problems/greatest-sum-divisible-by-three/description/
#include "xxx.hpp"

class Solution {
public:
  int maxSumDivThree(vector<int> &nums) {
    int ret = 0;
    // 1 <= nums[i] <= 10^4
    int min_mod_left1 = 20000;
    int min_mod_left2 = 20000;
    for (auto &cur : nums) {
      ret += cur;
      if ((cur % 3) == 1) {
        // 1 + 1 % 3 == 2
        min_mod_left2 = min(min_mod_left2, min_mod_left1 + cur);

        min_mod_left1 = min(min_mod_left1, cur);
      } else if ((cur % 3) == 2) {
        // 2 + 2 % 3 == 1
        min_mod_left1 = min(min_mod_left1, min_mod_left2 + cur);

        min_mod_left2 = min(min_mod_left2, cur);
      }
    }
    if (ret % 3 == 0) {
      return ret;
    }
    if (ret % 3 == 1) {
      return ret - min_mod_left1;
    }
    return ret - min_mod_left2;
  }
};
