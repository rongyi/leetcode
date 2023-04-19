// http://leetcode.com/problems/kth-largest-element-in-an-array/description/
#include "xxx.hpp"

class Solution {
public:
  int findKthLargest(vector<int> &nums, int k) {
    priority_queue<int> q;
    for (auto &num : nums) {
      q.push(num);
    }
    int cur = -1;
    while (k--) {
      cur = q.top();
      q.pop();
    }

    return cur;
  }
};
