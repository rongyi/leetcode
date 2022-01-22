// http://leetcode.com/problems/integer-replacement/description/
#include "xxx.hpp"

class Solution {
public:
  int integerReplacement(int n) {
    // 15->16->8->4->2->1
    // 15->14->7->8->4->2->1
    // we can notice that we prefer to take n+1 or n-1 which can do more /2 operation.
    // therefore,
    int ret = 0;
    long cp = n;
    while (cp != 1) {
      if (cp & 1) {
        ret++;
        if ((cp & 3)== 3 && cp > 3) {
          cp += 1;
        }
      }
      cp >>= 1;
      ret++;
    }

    return ret;

  }
};
