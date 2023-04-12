// http://leetcode.com/problems/reverse-words-in-a-string/description/
#include "xxx.hpp"

class Solution {
public:
  string reverseWords(string &s) {
    int sz = s.size();
    reverse(s.begin(), s.end());

    int valid_end = 0;
    for (int i = 0; i < sz; i++) {
      if (s[i] != ' ') {
        if (valid_end != 0) {
          s[valid_end++] = ' ';
        }
        int j = i;
        while (j < sz && s[j] != ' ') {
          s[valid_end++] = s[j++];
        }
        reverse(s.begin() + valid_end - (j - i), s.begin() + valid_end);

        i = j;
      }
    }
    s.erase(s.begin() + valid_end, s.end());

    return s;
  }
};

