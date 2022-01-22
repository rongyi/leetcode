// https://leetcode.com/problems/concatenation-of-array/
#include "xxx.hpp"

// what a shabi question!
class Solution {
public:
  vector<int> getConcatenation(vector<int> &nums) {
    int sz = nums.size();
    vector<int> ret(sz * 2);
    for (int i = 0; i < sz; ++i) {
      ret[i] = ret[i + sz] = nums[i];
    }

    return ret;
  }
};
