// http://leetcode.com/problems/132-pattern/description/
#include "xxx.hpp"

class Solution {
public:
  bool find132patternTLEAbsolutely(vector<int> &nums) {
    const int n = nums.size();
    if (n < 3) {
      return false;
    }
    for (int k = 0; k < n; ++k) {
      for (int i = 0; i < k; ++i) {
        for (int j = i + 1; j < k; ++j) {
          if (nums[i] < nums[k] && nums[j] > nums[k]) {
            return true;
          }
        }
      }
    }
    return false;
  }
  bool find132pattern(vector<int> &nums) {
    // i j k index
    // vi vj vj
    const int n = nums.size();
    if (n < 3) {
      return false;
    }
    int vi = numeric_limits<int>::max();
    for (int j = 0; j < n; ++j) {
      vi = min(vi, nums[j]);
      if (vi == nums[j]) {
        continue;
      }
      // now we have vi, vj, vi the min, vj is current value
      for (int k = n - 1; k > j; --k) {
        if (nums[k] > vi && nums[j] > nums[k]) {
          return true;
        }
      }
    }
    return false;
  }
};
