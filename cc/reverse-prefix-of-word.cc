// https://leetcode.com/problems/reverse-prefix-of-word/
#include "xxx.h"

class Solution {
public:
  string reversePrefix(string word, char ch) {
    for (int i = 0; i < word.size(); ++i) {
      if (word[i] == ch) {
        reverse(word.begin(), word.begin() + i + 1);
        break;
      }
    }
    return word;
  }
};