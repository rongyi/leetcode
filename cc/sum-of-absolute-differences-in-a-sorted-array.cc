// http://leetcode.com/problems/sum-of-absolute-differences-in-a-sorted-array/description/
#include "xxx.h"

class Solution {
public:
  vector<int> getSumAbsoluteDifferences(vector<int> &nums) {
    // TLE version
    // const int n = nums.size();
    // vector<vector<int>> m(n, vector<int>(n, 0));
    // vector<int> ret(n, 0);

    // for (int i = 0; i < n; ++i) {
    //   for (int j = i + 1; j < n; ++j) {
    //     // j比i大，nums非递减
    //     // m[i][j] = nums[j] - nums[i];
    //     // m[j][i] = m[i][j];
    //     auto d = nums[j] - nums[i];
    //     ret[i] += d;
    //     ret[j] += d;
    //   }
    // }

    // return ret;

    const int n = nums.size();
    // 用公式
    // sum[i] = nums[i] - nums[0] + (nums[i] - nums[1]) + ... + (nums[i] -
    // nums[i - 1])
    //          + nums[i] - nums[i]
    //          + (nums[i + 1] - nums[i]) + ... + (nums[n - 1] - nums[i])
    // ==> i * nums[i] - (nums[0] + nums[1] + ... + nums[i - 1])
    //     + (nums[i] + nums[i + 1] + ... + nums[n - 1]) - (n - i) nums[i]
    vector<int> psum(n + 1, 0);
    for (int i = 0; i < n; ++i) {
      psum[i + 1] = psum[i] + nums[i];
    }
    vector<int> ret(n, 0);
    for (int i = 0; i < n; ++i) {
      ret[i] = i * nums[i] - psum[i] + (psum[n] - psum[i]) - (n - i) * nums[i];
    }

    return ret;
  }
};
