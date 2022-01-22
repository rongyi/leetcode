// http://leetcode.com/problems/check-if-a-string-can-break-another-string/description/
#include "xxx.hpp"

class Solution {
public:
  bool checkIfCanBreak(string s1, string s2) {
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    // 完全错开了
    if (s1.front() >= s2.back() || s1.back() <= s2.front()) {
      return true;
    }
    // 有交集，那要排次序
    // relation unkown
    int relation = 0;
    for (int i = 0; i < s1.size(); ++i) {
      if (relation == 0) {
        if (s1[i] < s2[i]) {
          relation = -1;
        } else if (s1[i] > s2[i]) {
          relation = 1;
        }
      } else {
        // 确认已有的关系，不符合那就不行了，有cross的，有cross就排不了座次了
        if (relation == -1 && s1[i] > s2[i]) {
          return false;
        }
        if (relation == 1 && s1[i] < s2[i]) {
          return false;
        }
      }
    }

    return true;
  }
};
