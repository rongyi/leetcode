// https://leetcode.com/problems/min-max-game/
#include "xxx.hpp"

class Solution {
public:
  int minMaxGame(vector<int> &nums) {
    if (nums.size() == 1) {
      return nums[0];
    }
    bool getmin = true;
    vector<int> next_level;
    for (int i = 0; i < nums.size(); i += 2) {
      if (getmin) {
        next_level.push_back(min(nums[i], nums[i + 1]));
      } else {
        next_level.push_back(max(nums[i], nums[i + 1]));
      }
      getmin = !getmin;
    }

    return minMaxGame(next_level);
  }
};
