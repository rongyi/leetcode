// https://leetcode.com/problems/house-robber-iv/
#include "xxx.hpp"

class Solution {
public:
  int minCapability(vector<int> &nums, int k) {
    int l = 0;
    int r = 1e9;
    while (l < r) {
      auto mid = l + (r - l) / 2;
      if (check(nums, k, mid)) {
        r = mid;
      } else {
        l = mid + 1;
      }
    }

    return l;
  }

private:
  // check num in nums <=val which can not be neibor
  // and the total number <= k
  int check(vector<int> &nums, int k, int val) {
    int sz = nums.size();
    for (int i = 0; i < sz; i++) {
      if (nums[i] <= val) {
        k--;
        i++;
      }
      if (k == 0) {
        return true;
      }
    }
    return k == 0;
  }
};
