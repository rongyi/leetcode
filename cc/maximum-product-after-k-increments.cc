// https://leetcode.com/problems/maximum-product-after-k-increments/
#include "xxx.hpp"

class Solution {
public:
  int maximumProduct(vector<int> &nums, int k) {
    const int mod = 1e9 + 7;
    priority_queue<int, vector<int>, greater<int>> pq(nums.begin(), nums.end());
    while (k--) {
      auto cur = pq.top();
      pq.pop();
      pq.push(cur + 1);
    }
    long long ret = 1;

    while (!pq.empty()) {
      auto cur = pq.top();
      pq.pop();
      ret = (ret * cur) % mod;
    }

    return ret;
  }
};
