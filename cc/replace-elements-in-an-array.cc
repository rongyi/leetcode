// https://leetcode.com/problems/replace-elements-in-an-array/
#include "xxx.hpp"

class Solution {
public:
  vector<int> arrayChange(vector<int> &nums, vector<vector<int>> &operations) {
    map<int, int> value_idx;
    for (int i = 0; i < nums.size(); ++i) {
      value_idx[nums[i]] = i;
    }
    for (auto &ch : operations) {
      auto idx = value_idx[ch[0]];
      // change idx to value: ch[1];
      nums[idx] = ch[1];
      // erase old value indexer
      value_idx.erase(ch[0]);
      // add new indexer
      value_idx[ch[1]] = idx;
    }

    return nums;
  }
};
