// https://leetcode.com/problems/count-the-number-of-beautiful-subarrays/
#include "xxx.hpp"

class Solution {
public:
  long long beautifulSubarrays(vector<int> &nums) {
    int sz = nums.size();
    long long ret = 0;
    map<int, int> xor_val_cnt;
    xor_val_cnt[0] = 1;
    int val = 0;
    for (int i = 0; i < sz; i++) {
      val ^= nums[i];
      ret += xor_val_cnt[val]++;
    }

    return ret;
  }
};

class SolutionTLE {
public:
  // so they don't allow O(n^2)
  // but first get get the xor solution poc
  // now make this to O(n)
  // we need prefix xor
  long long beautifulSubarraysTLE(vector<int> &nums) {
    int sz = nums.size();
    long long ret = 0;
    for (int i = 0; i < sz; i++) {
      int val = nums[i];
      if (val == 0) {
        ret += 1;
      }
      for (int j = i + 1; j < sz; j++) {
        val ^= nums[j];
        if (val == 0) {
          ret += 1;
        }
      }
    }
    return ret;
  }
};
