// http://leetcode.com/problems/number-of-ways-where-square-of-number-is-equal-to-product-of-two-numbers/description/
#include "xxx.hpp"

class Solution {
public:
  int numTriplets(vector<int> &nums1, vector<int> &nums2) {
    auto sum1 =
        accumulate(nums1.begin(), nums1.end(), 0, [&](int acc, long cur) {
          return acc + count(cur * cur, nums2);
        });
    cache_.clear();
    auto sum2 =
        accumulate(nums2.begin(), nums2.end(), 0, [&](int acc, long cur) {
          return acc + count(cur * cur, nums1);
        });
    return sum1 + sum2;
  }

private:
  int count(long target, vector<int> nums) {
    if (cache_.find(target) != cache_.end()) {
      return cache_[target];
    }
    unordered_map<int, int> m;
    int ret = 0;
    for (auto num : nums) {
      // 这个trick很受用
      if (target % num == 0) {
        ret += m[target / num];
      }
      ++m[num];
    }
    cache_[target] = ret;

    return ret;
  }

private:
  unordered_map<int, int> cache_;
};
