// https://leetcode.com/problems/sum-of-beauty-in-the-array/
#include "xxx.h"

class Solution {
public:
  int sumOfBeauties(vector<int> &nums) {
    int sz = nums.size();
    // value put in 1..sz
    vector<int> left_max(sz + 1, 0);
    for (int i = 0; i < sz; ++i) {
      left_max[i + 1] = max(left_max[i], nums[i]);
    }
    vector<int> right_min(sz + 1, numeric_limits<int>::max());
    for (int i = sz - 1; i >= 0; --i) {
      // value put in 0..sz-1
      right_min[i] = min(right_min[i + 1], nums[i]);
    }
    int score = 0;

    for (int i = 1; i < sz - 1; ++i) {
      int cur_left_max = left_max[i /* - 1 + 1*/];
      int cur_right_min = right_min[i + 1];
      if (cur_left_max < nums[i] && nums[i] < cur_right_min) {
        score += 2;
      } else if (nums[i - 1] < nums[i] && nums[i] < nums[i + 1]) {
        score += 1;
      }
    }

    return score;
  }
};

int main() {
  Solution so;
  vector<int> input{1, 2, 3};
  so.sumOfBeauties(input);
}
