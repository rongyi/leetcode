// https://leetcode.com/problems/maximum-consecutive-floors-without-special-floors/
#include "xxx.hpp"

class Solution {
public:
  int maxConsecutive(int bottom, int top, vector<int> &special) {
    sort(special.begin(), special.end());
    int ret = max(special[0] - bottom, top - special.back());

    for (int i = 1; i < special.size(); ++i) {
      ret = max(ret, special[i] - special[i - 1] - 1);
    }

    return ret;
  }
};
