// https://leetcode.com/problems/number-of-valid-words-in-a-sentence/
#include "xxx.h"

class Solution {
public:
  int countValidWords(string s) {
    if (s.back() != ' ') {
      s.push_back(' ');
    }
    int ret = 0;
    int sz = s.size();
    for (int i = 0; i < sz;) {
      int j = i;
      // ignore leading space
      while (j < sz && s[j] == ' ') {
        j++;
      }
      if (j == sz) {
        break;
      }
      int wstart = j;
      while (j < sz && s[j] != ' ') {
        j++;
      }
      // now j stop at the first space
      string cur = s.substr(wstart, j - wstart);
      if (valid(cur)) {
        ret++;
      }

      i = j;
    }

    return ret;
  }

private:
  bool valid(string &s) {
    // 1. can not have digit
    // 2. only contain at most 1 '-'
    // If present, it must be surrounded by lowercase characters ("a-b" is
    // valid, but "-ab" and "ab-" are not valid).
    // 3. There is at most one punctuation mark. If present, it must be at the
    // end of the token ("ab,", "cd!", and "." are valid, but "a!b" and "c.,"
    // are not valid).
    int hypen_count = 0;
    int sz = s.size();
    for (int i = 0; i < sz; ++i) {
      if (isdigit(s[i])) {
        return false;
      } else if (s[i] == '-') {
        if (i == 0 || i == sz - 1) {
          return false;
        }
        // must be surrounded by two regular char
        if (!isalpha(s[i - 1]) || !isalpha(s[i + 1])) {
          return false;
        }
        hypen_count++;
      } else if (s[i] == '!' || s[i] == ',' || s[i] == '.') {
        if (i != sz - 1) {
          return false;
        }
      }
    }

    return hypen_count < 2;
  }
};
