// http://leetcode.com/problems/truncate-sentence/description/
#include "xxx.hpp"

class Solution {
public:
  string truncateSentence(string s, int k) {
    int n = s.size();
    int space_count = 0;
    int j = 0;
    for (int i = 0; i < n; ++i) {
      if (s[i] == ' ') {
        space_count++;
        if (space_count == k) {
          j = i;
          break;
        }
      }
    }
    // the match case, or we can push_back a space in s;
    if (j == 0) {
      return s;
    }

    return s.substr(0, j);
  }
};
