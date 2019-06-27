// http://leetcode.com/problems/orderly-queue/description/
#include "xxx.h"

class Solution {
public:
  string orderlyQueue(string S, int K) {
    if (K > 1) {
      sort(S.begin(), S.end());
      return S;
    }
    string lmin = S;
    for (int i = 1; i < S.size(); i++) {
      lmin = min(lmin, S.substr(i) + S.substr(0, i));
    }
    return lmin;
  }
};
