// https://leetcode.com/problems/maximum-number-of-words-found-in-sentences/
#include "xxx.hpp"

class Solution {
public:
  int mostWordsFound(vector<string> &sentences) {
    int spaces = 0;
    for (auto &s : sentences) {
      int cur_space = 0;
      for (int i = 0; i < s.size(); ++i) {
        if (s[i] == ' ') {
          cur_space += 1;
        }
      }
      spaces = max(spaces, cur_space);
    }

    return spaces + 1;
  }
};
