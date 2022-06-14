// https://leetcode.com/problems/rearrange-characters-to-make-target-string/
#include "xxx.hpp"

class Solution {
public:
  int rearrangeCharacters(string s, string target) {
    vector<int> cnt(26, 0);
    vector<int> tcnt(26, 0);
    for (auto c : s) {
      cnt[c - 'a']++;
    }
    for (auto c : target) {
      tcnt[c - 'a']++;
    }
    int ret = numeric_limits<int>::max();
    for (int i = 0; i < 26; ++i) {
      if (tcnt[i] != 0) {
        cnt[i] /= tcnt[i];
        ret = min(ret, cnt[i]);
        // we know this is the answer
        if (ret == 0) {
          return 0;
        }
      }
    }

    return ret;
  }
};
