// http://leetcode.com/problems/reverse-subarray-to-maximize-array-value/description/
#include "xxx.h"

class Solution {
public:
  // vobose description:
  // please *do* read this article
  // https://leetcode.com/problems/reverse-subarray-to-maximize-array-value/discuss/489882/O(n)-Solution-with-explanation
  int maxValueAfterReverse(vector<int> &nums) {
    int sum = 0;
    int min_start = numeric_limits<int>::max();
    int max_end = numeric_limits<int>::min();
    int ret = 0;

    const int n = nums.size();
    // case1: a [b...c] d, i.e. "inner" subarray
    // length of the yellow line = min(c,d) - max(a,b)
    for (int i = 1; i < n; i++) {
      sum += abs(nums[i] - nums[i - 1]);
      min_start = min(min_start, max(nums[i], nums[i - 1]));
      max_end = max(max_end, min(nums[i], nums[i - 1]));
    }

    ret = sum + max(0, (max_end - min_start) * 2);

    // case2: subarray start with 0 or end with n - 1
    // swap from i to j where i,j are either 0 or n-1: Assuming that i is 0 then
    // what we gain is |a[0]-a[j+1]| - |a[j]-a[j+1]|. Scan a second time to
    // calculate max gain.
    int t1 = 0;
    int t2 = 0;
    for (int i = 1; i < n - 1; i++) {
      // reverse subarray[0..i]
      t1 = max(t1, abs(nums[i + 1] - nums[0]) - abs(nums[i + 1] - nums[i]));
      // reverse subarray[i..n]
      t2 = max(t2, abs(nums[n - i - 1] - nums[n - 1]) -
                       abs(nums[n - i - 1] - nums[n - i]));
    }

    return max(ret, sum + max(t1, t2));
  }
};
