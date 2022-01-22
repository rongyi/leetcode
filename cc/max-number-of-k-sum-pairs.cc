// http://leetcode.com/problems/max-number-of-k-sum-pairs/description/
#include "xxx.hpp"

class Solution {
public:
  int maxOperations(vector<int> &nums, int k) {
    // using cache
    // map<int, int> count;
    // for (auto &n : nums) {
    //   count[n]++;
    // }
    // int ret = 0;
    // for (auto &n : nums) {
    //   if (n == k - n) {
    //     if (count[n] >= 2) {
    //       ret++;
    //       count[n] -= 2;
    //     }
    //   } else if (count[n] > 0 && count[k - n] > 0) {
    //     ret++;
    //     count[n]--;
    //     count[k - n]--;
    //   }
    // }

    // return ret;

    // binary
    int ret = 0;
    sort(nums.begin(), nums.end());
    int i = 0;
    int j = nums.size() - 1;
    while (i < j) {
      int cur = nums[i] + nums[j];
      if (cur == k) {
        ret++;
        i++;
        j--;
      } else if (cur > k) {
        j--;
      } else {
        i++;
      }
    }
    return ret;
  }
};
