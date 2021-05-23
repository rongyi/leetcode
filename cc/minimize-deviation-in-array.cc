// http://leetcode.com/problems/minimize-deviation-in-array/description/
#include "xxx.h"

class Solution {
public:
  // https://leetcode.com/problems/minimize-deviation-in-array/discuss/955262/C%2B%2B-intuitions-and-flip
  int minimumDeviation(vector<int> &nums) {
    int ret = numeric_limits<int>::max();
    int cur_min = numeric_limits<int>::max();

    // 1. 偶数不会升
    // 2. double odd once
    priority_queue<int> pq;
    for (auto &n : nums) {
      if (n & 1) {
        n *= 2;
      }
      pq.push(n);
      cur_min = min(cur_min, n);
    }

    while (pq.top() % 2 == 0) {
      ret = min(ret, pq.top() - cur_min);
      cur_min = min(cur_min, pq.top() / 2);
      pq.push(pq.top() / 2);
      pq.pop();
    }

    return min(ret, pq.top() - cur_min);
  }
};
