// https://leetcode.com/problems/check-whether-two-strings-are-almost-equivalent/
#include "xxx.hpp"

class Solution {
public:
  bool checkAlmostEquivalent(string word1, string word2) {
    vector<int> freq1(26, 0);
    vector<int> freq2(26, 0);
    for (auto &c: word1) {
      freq1[c - 'a']++;
    }
    for (auto &c: word2) {
      freq2[c - 'a']++;
    }
    for (int i= 0; i < 26; ++i) {
      if (abs(freq1[i] - freq2[i]) > 3) {
        return false;
      }
    }
    return true;
  }
};
