// https://leetcode.com/problems/frog-jump-ii/
#include "xxx.hpp"

class Solution {
public:
  int maxJump(vector<int> &stones) {
    int ret = stones[1] - stones[0];
    for (int i = 3; i < stones.size(); i += 2) {
      ret = max(ret, stones[i] - stones[i - 2]);
    }
    for (int i = 2; i < stones.size(); i += 2) {
      ret = max(ret, stones[i] - stones[i - 2]);
    }

    return ret;
  }
};
