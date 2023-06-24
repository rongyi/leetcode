// https://leetcode.com/problems/minimum-additions-to-make-valid-string/
#include "xxx.hpp"

class Solution {
public:
  int addMinimum(string word) {
    int sz = word.size();
    int fix = 0;
    int i = 0;
    while (i < sz) {
      int win = 1;
      // ab bc ac can all include to this window
      if (i + 1 < sz && word[i + 1] > word[i]) {
        win++;
        // the ab case
        if (word[i] == 'a' && word[i + 1] == 'b') {
          if (i + 2 < sz && word[i + 2] == 'c') {
            // abc perfect case
            i += 3;
          } else {
            // just ab
            fix += 3 - win;
            i += 2;
          }
        } else {
          // ac, bc case
          fix += 3 - win;
          i += 2;
        }
      } else {
        // single a, b, c, case
        fix += 3 - win;
        i++;
      }
    }

    return fix;
  }
};

int main() {
  Solution so;
  so.addMinimum("aaaaab");
}

