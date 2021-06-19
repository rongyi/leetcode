// http://leetcode.com/problems/maximum-score-from-removing-substrings/description/
#include "xxx.h"

class Solution {
public:
  int maximumGain(string s, int x, int y) {
    string a{"ab"};
    string b{"ba"};
    // ensure x is the max score
    if (x < y) {
      swap(a, b);
      swap(x, y);
    }

    return remove(s, a, x) + remove(s, b, y);
  }

public:
  int remove(string &s, string r, int x) {
    int i = 0;
    int ret = 0;
    for (int j = 0; j < s.size(); ++j) {
      s[i++] = s[j];
      if (i >= 2 && s[i - 2] == r[0] && s[i - 1] == r[1]) {
        i -= 2;
        ret += x;
      }
    }

    s.resize(i);
    return ret;
  }
};
