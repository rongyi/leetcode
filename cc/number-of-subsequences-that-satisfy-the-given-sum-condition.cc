// http://leetcode.com/problems/number-of-subsequences-that-satisfy-the-given-sum-condition/description/
#include "xxx.hpp"

class Solution {
public:
  // https://leetcode.com/problems/number-of-subsequences-that-satisfy-the-given-sum-condition/discuss/709227/JavaC%2B%2BPython-Two-Sum
  // Almost same as problem two sum.
  // If we want to know the count of subarray in sorted array A,
  // then it's exactly the same.
  // Make sure you can do two sum before continue.

  // Explanation
  // Sort input A first,
  // For each A[i], find out the maximum A[j]
  // that A[i] + A[j] <= target.

  // For each elements in the subarray A[i+1] ~ A[j],
  // we can pick or not pick,
  // so there are 2 ^ (j - i) subsequences in total.
  // So we can update res = (res + 2 ^ (j - i)) % mod.

  // We don't care the original elements order,
  // we only want to know the count of sub sequence.
  // So we can sort the original A, and the result won't change.
  int numSubseq(vector<int> &nums, int target) {
    const int mod = pow(10, 9) + 7;
    sort(nums.begin(), nums.end());
    const int n = nums.size();

    vector<int> pow(n, 1);
    for (int i = 1; i < n; ++i) {
      pow[i] = pow[i - 1] * 2 % mod;
    }

    int l = 0;
    int r = n - 1;
    int ret = 0;
    while (l <= r) {
      if (nums[l] + nums[r] > target) {
        r--;
      } else {
        ret = (ret + pow[r - l++]) % mod;
      }
    }

    return ret;
  }
};
