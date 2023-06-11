// https://leetcode.com/problems/count-the-number-of-vowel-strings-in-range/
#include "xxx.hpp"

class Solution {
public:
  int vowelStrings(vector<string> &words, int left, int right) {
    int sz = words.size();
    int ret = 0;
    auto isvowel = [](string &s) -> bool {
      auto start_valid = (s[0] == 'a') || (s[0] == 'o') || (s[0] == 'e') ||
                         (s[0] == 'i') || (s[0] == 'u');

      auto end_valid = (s[s.size() - 1] == 'a') || (s[s.size() - 1] == 'o') ||
                       (s[s.size() - 1] == 'e') || (s[s.size() - 1] == 'i') ||
                       (s[s.size() - 1] == 'u');
      return start_valid && end_valid;
    };
    for (int i = left; i <= right; i++) {
      ret += isvowel(words[i]);
    }

    return ret;
  }
};
