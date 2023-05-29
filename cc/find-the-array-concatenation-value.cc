// https://leetcode.com/problems/find-the-array-concatenation-value/
#include "xxx.hpp"

class Solution {
public:
  long long findTheArrayConcVal(vector<int> &nums) {
    long long sum = 0;
    int sz = nums.size();
    int i = 0;
    int j = sz - 1;

    for (; i < j; i++, j--) {
      string v = to_string(nums[i]) + to_string(nums[j]);
      sum += stoll(v);
    }

    if (sz & 1) {
      sum += nums[i]; // or j
    }

    return sum;
  }
};
