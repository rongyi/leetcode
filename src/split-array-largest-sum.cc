// http://leetcode.com/problems/split-array-largest-sum/description/
#include "xxx.h"

class Solution {
public:
  int splitArray(vector<int> &nums, int m) {
    int left = *max_element(nums.begin(), nums.end());
    int right = accumulate(nums.begin(), nums.end(), 0ll);
    while (left < right) {
      auto mid = left + (right - left) / 2;
      if (canSplit(nums, m - 1, mid)) {
        right = mid;
      } else {
        left = mid + 1;
      }
    }

    return left;
  }
private:
  bool canSplit(vector<int> &nums, int cuts, long long max) {
    int acc = 0;
    for (auto num : nums) {
      if (num > max) {
        return false;
      } else if (acc + num <= max) {
        acc += num;
      } else {
        --cuts;
        acc = num;
        if (cuts < 0) {
          return false;
        }
      }
    }

    return true;
  }
};
