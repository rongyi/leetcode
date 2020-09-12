// http://leetcode.com/problems/maximum-product-of-two-elements-in-an-array/description/
#include "xxx.h"

class Solution {
public:
  int maxProduct(vector<int> &nums) {
    priority_queue<int, vector<int>, std::less<int>> pq;
    for (auto i : nums) {
      pq.push(i);
    }

    auto big = pq.top();
    pq.pop();
    auto next_big = pq.top();
    pq.pop();

    return (big - 1) * (next_big - 1);
  }
};
