// http://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/description/
#include "xxx.hpp"

class Solution {
public:
  int smallestDivisor(vector<int> &nums, int threshold) {
    int sum;
    int mid;
    int left = 1;
    int right = 1e6;

    while (left < right) {
      mid = (left + right) / 2;
      sum = 0;
      for (auto num : nums) {
        // small trick to calculate ceil(n)
        sum += (num + mid - 1) / mid;
      }
      if (sum > threshold) {
        left = mid + 1;
      } else {
        right = mid;
      }
    }

    return left;
  }
};
