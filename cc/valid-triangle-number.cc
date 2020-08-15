// http://leetcode.com/problems/valid-triangle-number/description/
#include "xxx.h"

class Solution {
public:
  int triangleNumber(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    int ret = 0;
    const int n = nums.size();
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        for (int k = j + 1; k < n; k++) {
          if (nums[i] + nums[j] > nums[k]) {
            ++ret;
          }
        }
      }
    }

    return ret;
  }
};
