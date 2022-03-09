// https://leetcode.com/problems/divide-a-string-into-groups-of-size-k/
#include "xxx.hpp"

class Solution {
public:
  vector<string> divideString(string s, int k, char fill) {
    vector<string> ret;
    int sz = s.size();
    int i = 0;
    for (; i < sz; i += k) {
      ret.push_back(s.substr(i, k));
    }

    if (sz % k != 0) {
      // last one is useless
      ret.pop_back();
      ret.push_back(s.substr(i - k) + string(k - (sz % k), fill));
    }

    return ret;
  }
};
