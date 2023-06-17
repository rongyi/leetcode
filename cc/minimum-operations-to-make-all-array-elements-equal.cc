// https://leetcode.com/problems/minimum-operations-to-make-all-array-elements-equal/
#include "xxx.hpp"

class Solution {
public:
  vector<long long> minOperations(vector<int> &nums, vector<int> &queries) {
    sort(nums.begin(), nums.end());
    int sz = nums.size();
    vector<long long> prefix(sz + 1, 0ll);
    for (int i = 0; i < sz; i++) {
      prefix[i + 1] = prefix[i] + nums[i];
    }
    vector<long long> ret;

    // To find smaller numbers than query[i] we can sort the array and use
    // binary search Binary search over sorted nums to find index of query[i]
    // Then use prefix sums to find sum of number in smaller and larger segments
    // prefix[n] - prefix[i] is sum of numbers greater than or equal to query[i]
    // prefix[i] is sum of numbers smaller than query[i]
    // query[i] * i - prefix[i] is increments required
    // prefix[n] - prefix[i] - query[i] * (n - i) is decrements required
    // Total = query[i] * i - prefix[i] + prefix[n] - prefix[i] - query[i] * (n
    // - i)
    // Can be simplified to query[i] * (2 * i - n) + prefix[n] - 2 *
    // prefix[i]
    for (auto &q : queries) {
      auto i = lower_bound(nums.begin(), nums.end(), q) - nums.begin();
      ret.push_back(1ll * q * (2 * i - sz) + prefix[sz] -
                    2 * prefix[i /*- 1 + 1*/]);
    }

    return ret;
  }
};
