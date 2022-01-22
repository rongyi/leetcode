// http://leetcode.com/problems/two-sum/description/
#include "xxx.hpp"
class Solution {
public:
  vector<int> twoSum(vector<int> &nums, int target) {
    unordered_map<int, vector<int>> dict;
    // remember the index;
    for (int i = 0; i < nums.size(); ++i) {
      dict[nums[i]].push_back(i);
    }
    for (auto kv : dict) {
      auto delta = target - kv.first;
      if (dict.find(delta) != dict.end()) {
        if (delta == kv.first) {
          if (kv.second.size() > 1) {
            return vector<int>{kv.second[0], kv.second[1]};
          }
        } else {
          return vector<int>{kv.second[0], dict[delta][0]};
        }
      }
    }
    return vector<int>{};
  }
};
