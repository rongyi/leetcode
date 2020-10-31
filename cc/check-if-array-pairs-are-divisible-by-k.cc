// http://leetcode.com/problems/check-if-array-pairs-are-divisible-by-k/description/
#include "xxx.h"

class Solution {
public:
  bool canArrange(vector<int> &arr, int k) {
    long long total = accumulate(arr.begin(), arr.end(), 0ll);
    if (total % k != 0) {
      return false;
    }
    // 按余数分类
    unordered_map<int, vector<int>> group;
    for (auto &num : arr) {
      // 有负数，fuck
      group[((num % k) + k) % k].push_back(num);
    }
    // 能被整除的数应该是偶数个
    if (group[0].size() & 1) {
      return false;
    }
    for (int i = 1; i < k; ++i) {
      // 要能配对整除
      if (group[i].size() != group[k - i].size()) {
        return false;
      }
    }

    return true;
  }
};
