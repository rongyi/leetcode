// https://leetcode.com/problems/minimum-operations-to-halve-array-sum/
#include "xxx.hpp"

class Solution {
public:
  int halveArray(vector<int> &nums) {
    double sum = accumulate(nums.begin(), nums.end(), 0.0);

    // double type!
    priority_queue<double> pq(nums.begin(), nums.end());
    int change = 0;
    double shrink = sum;
    for (; shrink * 2 > sum; change++) {
      double top = pq.top();
      pq.pop();
      shrink -= top / 2;
      // if int type, this will get wrong answer
      pq.push(top / 2);
    }

    return change;
  }
};
