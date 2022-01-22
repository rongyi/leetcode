// https://leetcode.com/problems/maximum-number-of-words-you-can-type/
#include "xxx.hpp"

class Solution {
public:
  int canBeTypedWords(string text, string brokenLetters) {
    // make it more easy to process
    text.push_back(' ');
    vector<int> count(26, 0);
    for (auto &c : brokenLetters) {
      count[c - 'a']++;
    }
    bool valid = true;
    int ret = 0;
    for (int i = 0; i < text.size(); ++i) {
      if (text[i] == ' ') {
        ret += valid;
        valid = true;
      } else if (valid && count[text[i] - 'a'] > 0) {
        valid = false;
      }
    }
    return ret;
  }
};
