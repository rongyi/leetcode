// https://leetcode.com/problems/determine-the-winner-of-a-bowling-game/
#include "xxx.hpp"

class Solution {
public:
  int isWinner(vector<int> &player1, vector<int> &player2) {
    auto score = [](vector<int> &nums) {
      int sum = 0;
      int sz = nums.size();
      for (int i = 0; i < sz; i++) {
        if ((i > 0 && nums[i - 1] == 10) || (i > 1 && nums[i - 2] == 10)) {
          sum += nums[i] * 2;
        } else {
          sum += nums[i];
        }
      }
      return sum;
    };

    int s1 = score(player1);
    int s2 = score(player2);
    if (s1 > s2) {
      return 1;
    }
    if (s2 > s1) {
      return 2;
    }
    return 0;
  }
};
