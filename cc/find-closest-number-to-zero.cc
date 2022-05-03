// https://leetcode.com/problems/find-closest-number-to-zero/
#include "xxx.hpp"

class Solution {
public:
  // so easy
  int findClosestNumber(vector<int> &nums) {
    int ret = numeric_limits<int>::min();
    int dist = numeric_limits<int>::max();
    for (auto num : nums) {
      auto cur_dist = abs(num);
      if (cur_dist < dist) {
        dist = cur_dist;
        ret = num;
      } else if (cur_dist == dist) {
        if (num > ret) {
          ret = num;
        }
      }
    }

    return ret;
  }
};

