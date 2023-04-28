// http://leetcode.com/problems/missing-number/description/
#include "xxx.hpp"

class Solution {
public:
  int missingNumber(vector<int> &nums) {
    const int n = nums.size();

    return n * (n + 1) / 2 - accumulate(nums.begin(), nums.end(), 0);

    // method 2
    // sort(nums.begin(), nums.end());
    // int i = 0;
    // for (; i < nums.size(); i++) {
    // if (nums[i] != i) {
    // break;
    //}
    //}

    // return i;
  }
};
