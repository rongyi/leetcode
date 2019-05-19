// http://leetcode.com/problems/chalkboard-xor-game/description/
#include "xxx.h"

class Solution {
public:
  bool xorGame(vector<int> &nums) {
    int x = 0;
    for (auto num : nums) {
      x ^= num;
    }
    return x == 0 || nums.size() % 2 == 0;
  }
};
