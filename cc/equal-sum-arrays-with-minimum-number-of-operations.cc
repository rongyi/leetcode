// http://leetcode.com/problems/equal-sum-arrays-with-minimum-number-of-operations/description/
#include "xxx.hpp"

class Solution {
public:
  int minOperations(vector<int> &nums1, vector<int> &nums2) {
    const int m = nums1.size();
    const int n = nums2.size();

    int lmin = m;
    int lmax = m * 6;
    int rmin = n;
    int rmax = n * 6;
    // 压根就够不着
    if (lmin > rmax || lmax < rmin) {
      return -1;
    }

    int sum1 = accumulate(nums1.begin(), nums1.end(), 0);
    int sum2 = accumulate(nums2.begin(), nums2.end(), 0);
    if (sum1 > sum2) {
      // 保证nums1是小的那组
      swap(nums1, nums2);
    }
    // 小的加上去，大的减下来
    priority_queue<int, vector<int>, greater<int>> q1(nums1.begin(),
                                                      nums1.end());
    priority_queue<int> q2(nums2.begin(), nums2.end());
    int diff = abs(sum1 - sum2);
    int count = 0;
    while (diff > 0) {
      ++count;
      if (q1.empty() || (!q2.empty() && q2.top() - 1 > 6 - q1.top())) {
        diff -= q2.top() - 1;
        q2.pop();
      } else {
        diff -= 6 - q1.top();
        q1.pop();
      }
    }

    return count;
  }
};
