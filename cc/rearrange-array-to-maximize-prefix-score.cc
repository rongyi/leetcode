// https://leetcode.com/problems/rearrange-array-to-maximize-prefix-score/
#include "xxx.hpp"

class Solution {
public:
  int maxScore(vector<int> &nums) {
    // make our best to put negative value to end;
    sort(nums.rbegin(), nums.rend());
    int sz = nums.size();
    long long psum = 0;
    int score = 0;

    for (int i = 0; i < sz; i++) {
      psum += nums[i];
      if (psum > 0) {
        score += 1;
      }
    }

    return score;
  }
};
