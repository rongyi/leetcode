// https://leetcode.com/problems/count-the-number-of-good-subarrays/
#include "xxx.hpp"

class Solution {
public:
  long long countGood(vector<int> &nums, int k) {
    map<int, int> cnt;
    long long ret = 0;
    int cur = 0;
    int sz = nums.size();
    for (int j = 0, i = 0; j < sz; ++j) {
      // trick part, you don't need (n + 1) * n / 2;
      cur += cnt[nums[j]];
      cnt[nums[j]]++;

      for (; i < sz && cur >= k; ++i) {
        ret += (sz - j);
        cur -= cnt[nums[i]] - 1;
        cnt[nums[i]]--;
      }
    }

    return ret;
  }
};

