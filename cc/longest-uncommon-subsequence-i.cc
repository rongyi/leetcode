// http://leetcode.com/problems/longest-uncommon-subsequence-i/description/
#include "xxx.h"

class Solution {
public:
  // 被喷的特别惨的一道题
  int findLUSlength(string a, string b) {
    if (a == b) {
      return -1;
    }
    return max(a.size(), b.size());
  }
};
