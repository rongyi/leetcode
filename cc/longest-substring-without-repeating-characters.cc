// http://leetcode.com/problems/longest-substring-without-repeating-characters/description/
#include "xxx.hpp"

class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    int start = 0;
    map<char, int> idx;
    int ret = 0;
    for (int j = 0; j < s.size(); ++j) {
      if (idx.count(s[j])) {
        start = max(start, idx[s[j]] + 1);
      }
      ret = max(ret, j - start + 1);
      idx[s[j]] = j;
    }

    return ret;
  }
};

