// http://leetcode.com/problems/sum-of-unique-elements/description/
#include "xxx.hpp"

class Solution {
public:
  int sumOfUnique(vector<int> &nums) {
    map<int, int> count;
    for (auto &n : nums) {
      count[n]++;
    }
    int ret = 0;
    for (auto kv : count) {
      if (kv.second == 1) {
        ret += kv.first;
      }
    }

    return ret;
  }
};
