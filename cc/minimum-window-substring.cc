// http://leetcode.com/problems/minimum-window-substring/description/
#include "xxx.hpp"

class Solution {
public:
  string minWindow(string source, string target) {
    int sz = source.size();
    map<char, int> dict;
    for (auto &c : target) {
      dict[c]++;
    }
    int cnt = dict.size();

    int min_len = sz + 1;
    int start = -1;
    for (int j = 0, i = 0; j < sz; j++) {
      dict[source[j]]--;
      if (dict[source[j]] == 0) {
        cnt--;
      }
      if (cnt == 0) {
        while (cnt == 0) {
          if (min_len > j - i + 1) {
            min_len = j - i + 1;
            start = i;
          }
          dict[source[i]]++;
          if (dict[source[i]] > 0) {
            cnt++;
          }

          i++;
        }
      }
    }
    if (min_len == sz + 1) {
      return "";
    }
    return source.substr(start, min_len);
  }
};
