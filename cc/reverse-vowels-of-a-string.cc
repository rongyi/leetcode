// http://leetcode.com/problems/reverse-vowels-of-a-string/description/
#include "xxx.hpp"

class Solution {
public:
  string reverseVowels(string s) {
    const unordered_set<char> key{'a', 'o', 'e', 'i', 'u', 'A', 'O', 'E', 'I', 'U'};
    const int n = s.size();
    int i = 0;
    int j = n - 1;
    while (i < j) {
      if (key.find(s[i]) == key.end()) {
        i++;
        continue;
      }
      if (key.find(s[j]) == key.end()) {
        --j;
        continue;
      }
      // 遇到非元音字符了，不等的时候再换，否则懒得换了
      if (s[i] != s[j]) {
        swap(s[i], s[j]);
      }
      i++;
      --j;
    }
    return s;
  }
};
