// http://leetcode.com/problems/maximum-number-of-occurrences-of-a-substring/description/
#include "xxx.h"

class Solution {
public:
  // the maxSize is useless
  // just count the minSize *valid* substring  and check occurrences
  // valid means uniq char set <= maxLetters
  int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
    int ret = 0;
    const int len = s.size();
    // substring -> count
    unordered_map<string, int> count;
    bitset<26> b; // distinct letters

    for (int i = 0; i <= len - minSize; i++) {
      auto cur = s.substr(i, minSize);
      b.reset();
      for (auto c : cur) {
        b.set(c - 'a');
      }
      if (b.count() > maxLetters) {
        continue;
      }
      ret = max(ret, ++count[cur]);
    }

    return ret;
  }
};
