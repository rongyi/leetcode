// https://leetcode.com/problems/lexicographically-smallest-string-after-substring-operation/
#include "xxx.hpp"

class Solution {
public:
  // shitty problem
  string smallestString(string s) {
    int sz = s.size();
    int aidx = -1;

    for (int i = 0; i < sz; i++) {
      if (s[i] == 'a') {
        aidx = i;
        break;
      }
    }
    // replace them all
    if (aidx == -1) {
      for (int i = 0; i < sz; i++) {
        s[i] = (s[i] - 'a' - 1 + 26) % 26 + 'a';
      }
      return s;
    }
    // replace before
    if (aidx > 0) {
      for (int i = 0; i < aidx; i++) {
        s[i] = (s[i] - 'a' - 1 + 26) % 26 + 'a';
      }
      return s;
    }

    // first postion is 'a'
    bool have_change = false;
    // we first jump the first and see if we can find a substring without 'a'
    for (int i = 1; i < sz; i++) {
      if (s[i] != 'a') {
        s[i] = (s[i] - 'a' - 1 + 26) % 26 + 'a';
        have_change = true;
      } else {
        if (have_change) {
          break;
        }
      }
    }
    if (have_change) {
      return s;
    }

    for (int i = sz - 1; i >= 0; i--) {
      char c = (s[i] - 'a' - 1 + 26) % 26 + 'a';
      // fuck, we make string lexicographically bigger
      if (c == 'z') {
        if (!have_change) {
          // must use one change
          s[i] = c;
        }
        break;
      } else {
        s[i] = c;
        have_change = true;
      }
    }

    return s;
  }
};

int main() {
  Solution so;
  so.smallestString("cbabc");
}
