// https://leetcode.com/problems/minimum-moves-to-convert-string/
#include "xxx.h"
class Solution {
public:
  // recursive!
  int minimumMovesRecursive(string s) {
    int n = s.size();
    int i = 0;
    while (i < n && s[i] == 'O') {
      i++;
    }

    if (i == n) {
      return 0;
    }
    if (i + 3 >= n) {
      return 1;
    }

    return 1 + minimumMoves(s.substr(i + 3));
  }
  // or loop
  int minimumMoves(string s) {
    int cnt = 0;
    for (int i = 0; i < s.size();) {
      int j = i;
      while (j < s.size() && s[j] == 'O') {
        ++j;
      }
      if (j < s.size()) {
        ++cnt;
      }
      // ignore this group
      i = j + 3;
    }

    return cnt;
  }
};
