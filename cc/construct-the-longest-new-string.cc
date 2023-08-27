// https://leetcode.com/problems/construct-the-longest-new-string/
#include "xxx.hpp"

class Solution {
public:
  int longestString(int x, int y, int z) {
    int ret = 0;
    ret += min(x, y) * 4;
    // use all z
    ret += z * 2;
    // if there is one x or y left, append to form yxy or xyx
    if (x != y) {
      ret += 2;
    }

    return ret;
  }
};

