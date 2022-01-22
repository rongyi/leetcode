// http://leetcode.com/problems/first-unique-character-in-a-string/description/
#include "xxx.hpp"

class Solution {
public:
  int firstUniqChar(string s) {
    unordered_map<char, int> dict;
    for (auto c : s) {
      dict[c]++;
    }
    for (int i = 0; i < s.size(); i++) {
      if (dict[s[i]] == 1) {
        return i;
      }
    }
    return -1;
  }
};
