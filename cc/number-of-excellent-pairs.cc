// https://leetcode.com/problems/number-of-excellent-pairs/
#include "xxx.hpp"

class Solution {
public:
  long long countExcellentPairs(vector<int> &nums, int k) {
    // bitcount group
    vector<long long> cnt(30, 0);
    for (auto num : unordered_set<int>(nums.begin(), nums.end())) {
      ++cnt[__builtin_popcount(num)];
    }
    long long ret = 0;
    for (int i = 1; i < cnt.size(); ++i) {
      for (int j = 1; j < cnt.size(); ++j) {
        if (i + j >= k) {
          ret += (cnt[i] * cnt[j]);
        }
      }
    }

    return ret;
  }
};
