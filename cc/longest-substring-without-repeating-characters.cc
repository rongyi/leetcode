// http://leetcode.com/problems/longest-substring-without-repeating-characters/description/
#include "xxx.hpp"

class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    unordered_set<char> charset;
    const int n = s.size();
    int left = 0;
    int ret = 0;
    for (int i = 0; i < n; ) {
      if (charset.find(s[i]) == charset.end()) {
        charset.insert(s[i++]);
        ret = max(ret, (int)charset.size());
      } else {
        charset.erase(s[left++]);
      }
    }

    return ret;
  }
};
