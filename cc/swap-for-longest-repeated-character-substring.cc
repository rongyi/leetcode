// http://leetcode.com/problems/swap-for-longest-repeated-character-substring/description/
#include "xxx.h"

class Solution {
public:
  int maxRepOpt1(string str) {
    int ret = 0;
    for (auto ch = 'a'; ch <= 'z'; ++ch) {
      int i = 0;
      int j = 0;
      int gap = 0;
      while (i < str.size()) {
        gap += str[i++] != ch;
        if (gap > 1) {
          gap -= str[j++] != ch;
        }
      }

      ret = max(ret,
                // why min? tak aaab for example, ret is 3, not 4, because b
                // have no ch to swap
                min(i - j, (int)count_if(str.begin(), str.end(),
                                         [&](char ch1) { return ch1 == ch; })));
    }
    return ret;
  }
};
