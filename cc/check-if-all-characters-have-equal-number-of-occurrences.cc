// https://leetcode.com/problems/check-if-all-characters-have-equal-number-of-occurrences/
#include "xxx.hpp"
class Solution {
public:
  bool areOccurrencesEqual(string s) {
    vector<int> count(26, 0);
    for (auto &c : s) {
      count[c - 'a']++;
    }

    int target = -1;
    int i = 0;
    // take the first one as std target
    for (; i < 26; ++i) {
      if (count[i] > 0) {
        target = count[i];
        break;
      }
    }

    for (; i < 26; ++i) {
      if (count[i] > 0 && count[i] != target) {
        return false;
      }
    }
    return true;
  }
};
