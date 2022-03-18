// https://leetcode.com/problems/minimum-difference-in-sums-after-removal-of-elements/
#include "xxx.hpp"

class Solution {
public:
  long long minimumDifference(vector<int> &nums) {
    int sz = nums.size();
    int n = sz / 3;
    vector<long long> cache(sz, 0);

    // in left part we pop the bigger one, make sum as small as possible
    priority_queue<int> ql;
    // in right part we pop the small one, make sum as bigger as possible
    // in thisway two set meet a smaller diff
    priority_queue<int, vector<int>, greater<>> qr;
    long long cur_sum = 0;
    for (int i = sz - 1; i >= n; --i) {
      qr.push(nums[i]);
      cur_sum += nums[i];
      if (qr.size() > n) {
        cur_sum -= qr.top();
        qr.pop();
      }
      if (qr.size() == n) {
        cache[i] = cur_sum;
      }
    }

    cur_sum = 0;
    long long ret = numeric_limits<long long>::max();
    for (int i = 0; i < 2 * n; ++i) {
      ql.push(nums[i]);
      cur_sum += nums[i];
      if (ql.size() > n) {
        cur_sum -= ql.top();
        ql.pop();
      }
      if (ql.size() == n) {
        ret = min(ret, cur_sum - cache[i + 1]);
      }
    }
    return ret;
  }
};

