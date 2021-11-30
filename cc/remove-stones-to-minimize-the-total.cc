// https://leetcode.com/problems/remove-stones-to-minimize-the-total/
#include "xxx.h"

class Solution {
public:
  int minStoneSum(vector<int> &piles, int k) {
    // get minimum, so we shrink the maxinum number
    // we don't need to get the final arr and add to sum
    // we add total and minus the part we drop
    int sum = accumulate(piles.begin(), piles.end(), 0);
    priority_queue<int> q(piles.begin(), piles.end());
    while (k) {
      auto cur = q.top();
      q.pop();

      sum -= cur / 2;
      q.push(cur - cur / 2);

      // yeah, I know you can wirte k-- in while
      k--;
    }

    return sum;
  }
};
