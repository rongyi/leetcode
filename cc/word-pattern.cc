// http://leetcode.com/problems/word-pattern/description/
#include "xxx.hpp"

class Solution {
public:
  bool wordPattern(string pattern, string s) {
    int sz = pattern.size();
    stringstream ss(s);
    string cur;
    vector<string> words;
    while (getline(ss, cur, ' ')) {
      words.push_back(cur);
    }
    if (words.size() != sz) {
      return false;
    }
    map<char, string> bind;
    map<string, char> bind2;
    for (int i = 0; i < sz; i++) {
      char c = pattern[i];
      if (!bind.count(c) && !bind2.count(words[i])) {
        bind[c] = words[i];
        bind2[words[i]] = c;
      } else if (words[i] != bind[c] || bind2[words[i]] != c) {
        return false;
      }
    }

    return true;
  }
};
