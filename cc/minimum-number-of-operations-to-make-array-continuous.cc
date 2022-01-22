// https://leetcode.com/problems/minimum-number-of-operations-to-make-array-continuous/
#include "xxx.hpp"

class Solution {
public:
  // get the length of the longest subarray whose difference between min and max
  // elements is N - 1
  int minOperations(vector<int> &nums) {
    int n = nums.size();
    int ret = n;
    int j = 0;
    sort(nums.begin(), nums.end());
    nums.erase(unique(nums.begin(), nums.end()), nums.end());
    int m = nums.size();

    for (int i = 0; i < m; ++i) {
      // let j point the first ele out of range nums[i] + n
      while (j < m && nums[j] < nums[i] + n) {
        ++j;
      }
      // valid subarray length is: j - i;
      // we need n - (j - i) to modify
      ret = min(ret, n - j + i);
    }
    return ret;
  }
};
