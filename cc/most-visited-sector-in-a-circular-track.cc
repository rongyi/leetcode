// http://leetcode.com/problems/most-visited-sector-in-a-circular-track/description/
#include "xxx.h"

class Solution {
public:
  // 喷的很惨
  vector<int> mostVisited(int n, vector<int> &r) {
    vector<int> ret;
    // 取之间的range
    for (int i = r[0]; i <= r[r.size() - 1]; ++i) {
      ret.push_back(i);
    }
    if (ret.size() > 0) {
      return ret;
    }

    // 取外部的range，now start == last, end == begin
    // 取 1 ==> end
    for (int i = 1; i <= r[r.size() - 1]; ++i) {
      ret.push_back(i);
    }
    // 取 start ==> n
    for (int i = r[0]; i <= n; ++i) {
      ret.push_back(i);
    }
    return ret;
  }
};
