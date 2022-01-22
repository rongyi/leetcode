// http://leetcode.com/problems/pairs-of-songs-with-total-durations-divisible-by-60/description/
#include "xxx.hpp"

class Solution {
public:
  int numPairsDivisibleBy60(vector<int> &time) {
    vector<int> count(60, 0);
    int ret = 0;
    for (auto t : time) {
      ret += count[(60 - t % 60) % 60];
      ++count[t % 60];
    }

    return ret;
  }
};
