// https://leetcode.com/problems/letter-case-permutation/description/
#include "one.h"

class Solution {
public:
  vector<string> letterCasePermutation(string S) {
    // count non digits
    int count = 0;
    for (auto c : S) {
      // then it is a letter
      if (c > '9') {
        ++count;
      }
    }
    vector<string> ret;
    for (int i = 0; i < (1 << count); ++i) {
      string cur{""};
      int j = 0;
      for (auto c : S) {
        if (c > '9') {
          if (((i >> j++) & 1) == 1) {
            cur.push_back(toupper(c));
          } else {
            cur.push_back(tolower(c));
          }

        } else {
          cur.push_back(c);
        }
      }

      ret.push_back(cur);
    }

    return ret;
  }
};
