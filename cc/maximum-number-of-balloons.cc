// http://leetcode.com/problems/maximum-number-of-balloons/description/
#include "xxx.hpp"

class Solution {
public:
  int maxNumberOfBalloons(string text) {
    int ret = numeric_limits<int>::max();
    vector<int> count(26, 0);
    for (auto &c : text) {
      ++count[c - 'a'];
    }
    count['l' - 'a'] /= 2;
    count['o' - 'a'] /= 2;
    for (auto c : string{"balon"}) {
      ret = min(ret, count[c - 'a']);
    }

    return ret;
  }
};
