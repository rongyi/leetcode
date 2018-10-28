// http://leetcode.com/problems/kth-largest-element-in-an-array/description/
#include "simpleone.h"

class Solution {
public:
  // 考察大顶堆、小顶堆的问题
  int findKthLargest(vector<int> &nums, int k) {
    priority_queue<int, vector<int>, less<int>> q;
    for (auto i : nums) {
      q.push(i);
    }
    // to make top from 0
    k--;
    while (k) {
      q.pop();
      k--;
    }
    return q.top();
  }
};
