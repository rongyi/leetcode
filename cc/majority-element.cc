// http://leetcode.com/problems/majority-element/description/
#include "xxx.hpp"

class Solution {
public:
  // 其实人家考察的是选举算法，这么写没什么意思
  int majorityElement(vector<int> &nums) {
    const int n = nums.size() / 2;
    unordered_map<int, int> count;

    for (auto i : nums) {
      ++count[i];
      if (count[i] > n) {
        return i;
      }
    }

    for (auto kv : count) {
      if (count[kv.first] > n) {
        return kv.first;
      }
    }
    return -1;
  }
};
