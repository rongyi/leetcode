// http://leetcode.com/problems/detect-capital/description/
#include "xxx.h"

class Solution {
public:
  bool detectCapitalUse(string word) {
    // 可大可小，随便
    if (word.size() == 1) {
      return true;
    }

    bool is_initial_uppper = isupper(word[0]);
    if (is_initial_uppper) {
      bool has_upper = false;
      bool has_lower = false;
      for (int i = 1; i < word.size(); i++) {
        if (isupper(word[i])) {
          has_upper = true;
        } else {
          has_lower = true;
        }
        if (has_upper && has_lower) {
          return false;
        }
      }

    } else {
      // then it should be all lower case
      for (int i = 1; i < word.size(); i++) {
        if (isupper(word[i])) {
          return false;
        }
      }
    }

    return true;
  }
};
