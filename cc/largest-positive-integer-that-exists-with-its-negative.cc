// https://leetcode.com/problems/largest-positive-integer-that-exists-with-its-negative/
#include "xxx.hpp"

class Solution {
public:
  int findMaxK(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    int sz = nums.size();
    set<int> negs;
    for (auto &n: nums) {
      if (n > 0) {
        break;
      }
      negs.insert(n);
    }
    for (int i = sz - 1; i>= 0; --i) {
      if (nums[i] > 0 && negs.count(-nums[i])) {
        return nums[i];
      }
    }

    return -1;
  }
};
