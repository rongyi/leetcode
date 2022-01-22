// http://leetcode.com/problems/tuple-with-same-product/description/
#include "xxx.hpp"

class Solution {
public:
  // 注意uniq条件的应用
  int tupleSameProduct(vector<int> &nums) {
    unordered_map<int, int> mul_count;
    const int n = nums.size();
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        mul_count[nums[i] * nums[j]]++;
      }
    }
    int ret = 0;
    for (auto &kv : mul_count) {
      if (kv.second > 1) {
        // 实际是 n * (n - 1) / 2 * 8
        ret += kv.second * (kv.second - 1) * 4;
      }
    }

    return ret;
  }
};
