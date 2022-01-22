// http://leetcode.com/problems/construct-target-array-with-multiple-sums/description/
#include "xxx.hpp"

class Solution {
public:
  bool isPossible(vector<int> &target) {
    auto s = accumulate(target.begin(), target.end(), 0ll);
    priority_queue<int> q(target.begin(), target.end());

    while (s > 1 && q.top() > s / 2) {
      auto cur = q.top();
      q.pop();
      s -= cur;
      if (s <= 1) {
        return s;
      }

      // 这样去理解就可以了
      // q.push(cur - s);
      // s += cur - s;
      // 遇到有个数特别大的情况，需要碾掉,因为余下的那些数被加到这个数上很多次
      // 这是我见过 % 用的最巧妙的地方了
      q.push(cur % s);
      s += cur % s;
    }

    return s == target.size();
  }
};
