// http://leetcode.com/problems/expressive-words/description/
#include "xxx.hpp"

class Solution {
public:
  int expressiveWords(string S, vector<string> &words) {
    int ret = 0;
    for (auto w : words) {
      if (match(S, w)) {
        ++ret;
      }
    }
    return ret;
  }
private:
  bool match(const string &s, const string &word) {
    int i = 0;
    int j = 0;
    const int sn = s.size();
    const int wn = word.size();
    while (i < sn && j < wn) {
      // 要么相等
      if (s[i++] != word[j++]) {
        return false;
      }
      int counts = 1;
      int countw = 1;
      while (i < sn && s[i] == s[i - 1]) {
        ++counts;
        ++i;
      }
      while (j < wn && word[j] == word[j - 1]) {
        ++countw;
        ++j;
      }
      // 要么重复数字相等，要么重复的数字符合strechy的要求，即S重复要大于3，对比字符重复数字小于这个值
      if ((counts == countw) || (counts >= 3 && (countw < counts))) {
        continue;
      }
      return false;
    }
    return (i == sn) && (j == wn);
  }
};
