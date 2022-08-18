// https://leetcode.com/problems/subarray-with-elements-greater-than-varying-threshold/
#include "xxx.hpp"

class Solution {
public:
  int validSubarraySize(vector<int> &nums, int threshold) {
    int n = nums.size();
    vector<int> right(n, n);
    vector<int> left(n, -1);
    vector<int> s;

    // make sure cur num in range from [left[i] + 1 to right[i] - 1]
    // is the smallest one
    for (int i = 0; i < n; ++i) {
      while (!s.empty() && nums[i] < nums[s.back()]) {
        right[s.back()] = i;
        s.pop_back();
      }
      s.push_back(i);
    }
    s.clear();
    for (int i = n - 1; i >= 0; --i) {
      while (!s.empty() && nums[i] < nums[s.back()]) {
        left[s.back()] = i;
        s.pop_back();
      }
      s.push_back(i);
    }

    for (int i = 0; i < n; ++i) {
      long long len = right[i] - left[i] - 1;
      if ((nums[i] * len) > threshold) {
        return len;
      }
    }

    return -1;
  }
};
