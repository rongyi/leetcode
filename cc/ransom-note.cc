// http://leetcode.com/problems/ransom-note/description/
#include "xxx.h"

class Solution {
public:
  bool canConstruct(string ransomNote, string magazine) {
    unordered_map<char, int> rcount;
    unordered_map<char, int> mcount;

    for (auto c : ransomNote) {
      rcount[c]++;
    }
    for (auto c : magazine) {
      mcount[c]++;
    }

    for (auto c : ransomNote) {
      // character not in magzine
      if (mcount.find(c) == mcount.end()) {
        return false;
      }
      // char not enough
      if (mcount[c] < rcount[c]) {
        return false;
      }
    }

    return true;
  }
};
