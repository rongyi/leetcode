// https://leetcode.com/problems/minimum-swaps-to-group-all-1s-together-ii/
#include "xxx.hpp"

class Solution {
public:
  int minSwaps(vector<int> &nums) {
    int sz = nums.size();
    int ones = count(nums.begin(), nums.end(), 1);
    // input modified!
    // make it more fast
    nums.reserve(sz * 2);
    for (int i = 0; i < sz; ++i) {
      nums.push_back(nums[i]);
    }
    // max 1 in a window
    int ones_in_win = 0;
    // current 1 in a window
    int cur_one_in_win = 0;
    for (int i = 0; i < sz * 2; ++i) {
      if (i >= ones && nums[i - ones] == 1) {
        cur_one_in_win--;
      }
      if (nums[i] == 1) {
        cur_one_in_win++;
      }
      ones_in_win = max(ones_in_win, cur_one_in_win);
    }

    return ones - ones_in_win;
  }
};
