// https://leetcode.com/problems/intersection-of-multiple-arrays/
#include "xxx.hpp"

class Solution {
public:
  vector<int> intersection(vector<vector<int>> &nums) {
    int m = nums.size();
    map<int, int> cnt;
    // each num in a row is uniq, so when
    // it occurs at all rows, its count should be m
    for (auto &row : nums) {
      for (auto &num : row) {
        ++cnt[num];
      }
    }

    vector<int> ret;
    for (auto kv : cnt) {
      if (kv.second == m) {
        ret.push_back(kv.first);
      }
    }
    sort(ret.begin(), ret.end());

    return ret;
  }
};
