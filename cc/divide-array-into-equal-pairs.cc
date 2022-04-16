// https://leetcode.com/problems/divide-array-into-equal-pairs/
#include "xxx.hpp"

class Solution {
public:
  bool divideArray(vector<int> &nums) {
    map<int, int> count;
    for (auto &n : nums) {
      count[n]++;
    }
    for (auto &kv : count) {
      if (kv.second % 2 != 0) {
        return false;
      }
    }
    return true;
  }
};
