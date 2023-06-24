// https://leetcode.com/problems/maximum-sum-with-exactly-k-elements/
#include "xxx.hpp"

class Solution {
public:
  int maximizeSum(vector<int> &nums, int k) {
    int base = *max_element(nums.begin(), nums.end());

    return (base + base + k - 1) * k / 2;
  }
};
