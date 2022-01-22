// http://leetcode.com/problems/find-the-highest-altitude/description/
#include "xxx.hpp"

class Solution {
public:
  int largestAltitude(vector<int> &gain) {
    int height = 0;
    int ret = height;
    for (auto &diff : gain) {
      height += diff;
      ret = max(ret, height);
    }

    return ret;
  }
};
