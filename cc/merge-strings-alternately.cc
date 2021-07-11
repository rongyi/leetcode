// http://leetcode.com/problems/merge-strings-alternately/description/
#include "xxx.h"

class Solution {
public:
  string mergeAlternately(string word1, string word2) {
    string ret{};
    const int m = word1.size();
    const int n = word2.size();
    int i = 0;
    int j = 0;
    bool is_first = true;
    while (i < m && j < n) {
      if (is_first) {
        ret.push_back(word1[i++]);
      } else {
        ret.push_back(word2[j++]);
      }
      is_first ^= true;
    }
    if (i < m) {
      ret += word1.substr(i);
    } else {
      ret += word2.substr(j);
    }

    return ret;
  }
};
