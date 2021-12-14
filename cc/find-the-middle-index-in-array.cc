// https://leetcode.com/problems/find-the-middle-index-in-array/
#include "xxx.h"

class Solution {
public:
  int findMiddleIndex(vector<int> &nums) {
    int n = nums.size();
    vector<int> prefix_sum(n + 1, 0);
    for (int i = 0; i < n; ++i) {
      prefix_sum[i + 1] = prefix_sum[i] + nums[i];
    }

    for (int i = 0; i < n; ++i) {
      // left part 0 .. i - 1 => prefix_sum[i]

      // right part i + 1 .. n - 1 ==> prefix_sum[n] - prefix_sum[i + 1 - 1 + 1]
      if (prefix_sum[i] == (prefix_sum[n] - prefix_sum[i + 1])) {
        return i;
      }
    }

    return -1;
  }
};
