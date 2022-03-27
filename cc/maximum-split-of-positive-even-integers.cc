// https://leetcode.com/problems/maximum-split-of-positive-even-integers/
#include "xxx.hpp"

class Solution {
public:
  vector<long long> maximumEvenSplit(long long finalSum) {
    if (finalSum & 1) {
      return {};
    }
    vector<long long> ret;
    dfs(finalSum, 0, ret);

    return ret;
  }

  void dfs(long long cur, long long last, vector<long long> &ret) {
    // try to split an even number which is bigger than last
    if (cur - last <= last) {
      // combine the last two to one number
      if (ret.back() >= cur) {
        auto last = ret.back();
        ret.pop_back();
        ret.push_back(last + cur);
      } else {
        ret.push_back(cur);
      }
      return;
    }

    last += 2;
    ret.push_back(last);
    dfs(cur - last, last, ret);
  }
};

