// http://leetcode.com/problems/convert-to-base-2/description/
#include "xxx.h"

class Solution {
public:
  string baseNeg2(int N) {
    ostringstream ss;

    while (N) {
      ss << (N & 1);
      N = -(N >> 1);
    }
    auto ret = ss.str();
    reverse(ret.begin(), ret.end());

    if (ret == "") {
      return "0";
    }
    return ret;
  }
};
