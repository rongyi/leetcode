// http://leetcode.com/problems/find-all-duplicates-in-an-array/description/
#include "xxx.hpp"

class Solution {
public:
  vector<int> findDuplicates(vector<int> &nums) {
    unordered_map<int, int> count;
    for (auto i : nums) {
      count[i]++;
    }
    vector<int> ret;
    for (auto kv : count) {
      if (kv.second > 1) {
        ret.push_back(kv.first);
      }
    }
    return ret;
  }
};
