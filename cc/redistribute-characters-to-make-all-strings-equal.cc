#include "xxx.hpp"

class Solution {
public:
  bool makeEqual(vector<string> &words) {
    int sz = words.size();
    vector<int> count(26, 0);
    for (auto &w : words) {
      for (auto c : w) {
        count[c - 'a']++;
      }
    }
    for (int i = 0; i < 26; ++i) {
      if (count[i] % sz) {
        return false;
      }
    }
    return true;
  }
};
