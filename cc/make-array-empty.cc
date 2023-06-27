// https://leetcode.com/problems/make-array-empty/
#include "xxx.hpp"

class Solution {
public:
  long long countOperationsToEmptyArray(vector<int> &nums) {
    map<int, int> idx;
    int sz = nums.size();
    for (int i = 0; i < sz; i++) {
      idx[nums[i]] = i;
    }
    sort(nums.begin(), nums.end());
    long long ret = sz;
    for (int i = 1; i < sz; i++) {
      if (idx[nums[i]] < idx[nums[i - 1]]) {
        ret += (sz - i);
      }
    }

    return ret;
  }
};
