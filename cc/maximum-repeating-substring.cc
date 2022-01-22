// http://leetcode.com/problems/maximum-repeating-substring/description/
#include "xxx.hpp"

class Solution {
public:
  int maxRepeating(string sequence, string word) {
    string grow = word;
    auto cur = sequence.find(grow);

    int ret = 0;

    while (cur != string::npos) {
      ret++;
      grow += word;
      cur = sequence.find(grow);
    }

    return ret;
  }
};
