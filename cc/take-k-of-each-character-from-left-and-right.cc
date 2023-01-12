// https://leetcode.com/problems/take-k-of-each-character-from-left-and-right/
#include "xxx.hpp"

class Solution {
public:
  int takeCharacters(string s, int k) {
    int sz = s.size();
    vector<int> cnt(3, 0);
    for (auto &c : s) {
      cnt[c - 'a']++;
    }
    for (int i = 0; i < 3; i++) {
      if (cnt[i] < k) {
        return -1;
      }
    }
    int i = 0;
    int win = 0;
    int ret = sz;
    for (int j = 0; j < sz; ++j) {
      cnt[s[j] - 'a']--;
      win++;
      while (cnt[s[j] - 'a'] < k) {
        cnt[s[i] - 'a']++;
        i++;
        win--;
      }
      ret = min(ret, sz - win);
    }
    return ret;
  }
};
