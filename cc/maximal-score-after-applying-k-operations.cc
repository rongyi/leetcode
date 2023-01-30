// https://leetcode.com/problems/maximal-score-after-applying-k-operations/
#include "xxx.hpp"

class Solution {
public:
  long long maxKelements(vector<int> &nums, int k) {
    priority_queue<int> pq;
    for (auto &num : nums) {
      pq.push(num);
    }
    long long sum = 0;
    while (k--) {
      auto cur = pq.top();
      pq.pop();
      sum += cur;
      int ceil = cur / 3;
      if (cur % 3) {
        ceil += 1;
      }
      pq.push(ceil);
    }
    return sum;
  }
};
