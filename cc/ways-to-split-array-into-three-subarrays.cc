// http://leetcode.com/problems/ways-to-split-array-into-three-subarrays/description/
#include "xxx.h"

class Solution {
public:
  int waysToSplit(vector<int> &nums) {
    const int n = nums.size();
    auto prefix = nums;
    for (int i = 1; i < n; ++i) {
      prefix[i] += prefix[i - 1];
    }

    int sum = prefix.back();
    long long ret = 0;
    const int mod = 1e9 + 7;

    int third_section = 0;
    for (int i = n - 1; i >= 2; --i) {
      third_section += nums[i];
      // 3 sections sum as
      // a | b | c and a + b + c = sum
      // a | sum - (a + c) | c
      // a <= sum - (a + c)
      // sum-(a + c) <= c
      // make c as constant we get
      // sum - 2c  <= a <= (sum - c) / 2
      auto cur = count_range(prefix, i - 1, sum - 2 * third_section,
                             (sum - third_section) / 2);
      ret = (ret + cur) % mod;
    }

    return ret;
  }

private:
  int count_range(vector<int> &prefix, int end, int low, int high) {
    if (low > high) {
      return 0;
    }
    auto l = lower_bound(prefix.begin(), prefix.begin() + end, low);
    auto r = upper_bound(prefix.begin(), prefix.begin() + end, high);

    return r - l;
  }
};
