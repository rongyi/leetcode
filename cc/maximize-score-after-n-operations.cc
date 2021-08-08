// http://leetcode.com/problems/maximize-score-after-n-operations/description/
#include "xxx.h"

class Solution {
public:
  int maxScore(vector<int> &nums, int round = 1, int mask = 0) {
    if (round > nums.size() / 2) {
      return 0;
    }
    if (!dp_[round][mask]) {
      for (int i = 0; i < nums.size(); ++i) {
        for (int j = i + 1; j < nums.size(); ++j) {
          int next_mask = (1 << i) + (1 << j);
          if ((mask & next_mask) == 0) {
            dp_[round][mask] =
                max(dp_[round][mask],
                    round * __gcd(nums[i], nums[j]) +
                        maxScore(nums, round + 1, mask + next_mask));
          }
        }
      }
    }

    return dp_[round][mask];
  }

private:
  int dp_[8][16384] = {};
};
