// http://leetcode.com/problems/determine-if-two-strings-are-close/description/
#include "xxx.h"

class Solution {
public:
  bool closeStrings(string word1, string word2) {
    vector<int> t1(26, 0);
    vector<int> t2(26, 0);
    for (auto &c : word1) {
      t1[c - 'a']++;
    }
    for (auto &c : word2) {
      t2[c - 'a']++;
    }
    for (int i = 0; i < 26; ++i) {
      if ((t1[i] && !t2[i]) || (t2[i] && !t1[i])) {
        return false;
      }
    }
    sort(t1.begin(), t1.end());
    sort(t2.begin(), t2.end());
    return t1 == t2;
  }
};
