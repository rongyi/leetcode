// https://leetcode.com/problems/k-divisible-elements-subarrays/
#include "xxx.hpp"

class Solution {
public:
  // brute force
  int countDistinct(vector<int> &nums, int k, int p) {
    set<vector<int>> uniq;
    int sz = nums.size();

    for (int i = 0; i < sz; ++i) {
      vector<int> cur;
      int cnt = 0;
      for (int j = i; j < sz; ++j) {
        cur.push_back(nums[j]);
        if (nums[j] % p == 0) {
          ++cnt;
        }
        if (cnt > k) {
          break;
        }
        uniq.insert(cur);
      }
    }


    return uniq.size();
  }
};
