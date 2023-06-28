// https://leetcode.com/problems/ind-the-distinct-difference-array/
#include "xxx.hpp"

class Solution {
public:
  vector<int> distinctDifferenceArray(vector<int> &nums) {
    int sz = nums.size();
    vector<int> prefix(sz, 0);
    vector<int> suffix(sz, 0);

    set<int> uniq;
    for (int i = 0; i < sz; i++) {
      uniq.insert(nums[i]);
      prefix[i] = uniq.size();
    }
    uniq.clear();
    for (int i = sz - 1; i >= 0; i--) {
      suffix[i] = uniq.size();
      uniq.insert(nums[i]);
    }
    for (int i = 0; i < sz; i++) {
      prefix[i] -= suffix[i];
    }
    return prefix;
  }
};
