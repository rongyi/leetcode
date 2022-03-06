// https://leetcode.com/problems/capitalize-the-title/
#include "xxx.hpp"

class Solution {
public:
  string capitalizeTitle(string s) {
    int sz = s.size();
    for (int i = 0; i < sz;) {
      int j = i;
      while (j < sz && s[j] != ' ') {
        j++;
      }
      int len = j - i;
      if (len <= 2) {
        for (int k = i; k < j; ++k) {
          s[k] = tolower(s[k]);
        }
      } else {
        s[i] = toupper(s[i]);
        for (int k = i + 1; k < j; ++k) {
          s[k] = tolower(s[k]);
        }
      }

      i = j + 1;
    }

    return s;
  }
};

