// http://leetcode.com/problems/rearrange-spaces-between-words/description/
#include "xxx.hpp"

class Solution {
public:
  string reorderSpaces(string s) {
    int total_spaces = 0;
    int word = 0;
    int i = 0;
    vector<string> input;
    while (i < s.length()) {
      if (s[i] == ' ') {
        total_spaces++;
        i++;
      } else {
        word++;
        int start = i;
        while (i < s.length() && s[i] != ' ') {
          ++i;
        }
        input.push_back(s.substr(start, i - start));
      }
    }
    if (word == 1) {
      return input[0] + string(total_spaces, ' ');
    }

    ostringstream ss;
    int gap = total_spaces / (word - 1);
    int left = total_spaces % (word - 1);
    for (int i = 0; i < word; ++i) {
      ss << input[i] << string(gap, ' ');
    }

    auto ret = ss.str();
    for (int i = 0; i < gap; ++i) {
      ret.pop_back();
    }

    ret += string(left, ' ');

    return ret;
  }
};
