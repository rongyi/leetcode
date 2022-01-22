// http://leetcode.com/problems/find-words-that-can-be-formed-by-characters/description/
#include "xxx.hpp"

class Solution {
public:
  int countCharacters(vector<string> &words, string chars) {
    int ret = 0;
    unordered_map<char, int> count;
    for (auto &c : chars) {
      ++count[c];
    }
    for (auto &w : words) {
      unordered_map<char, int> cur;
      for (auto &c : w) {
        ++cur[c];
      }
      bool can{true};
      for (auto &curkv : cur) {
        if (count.find(curkv.first) == count.end() ||
            curkv.second > count[curkv.first]) {
          can = false;
          break;
        }
      }
      if (can) {
        ret += w.size();
      }
    }

    return ret;
  }
};
