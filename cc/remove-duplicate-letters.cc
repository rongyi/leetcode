// http://leetcode.com/problems/remove-duplicate-letters/description/
#include "xxx.hpp"

class Solution {
public:
  string removeDuplicateLetters(string s) {
    map<char, int> cnt;
    map<char, bool> used;
    for (auto &c : s) {
      cnt[c]++;
    }
    string ret;

    for (auto &c : s) {
      cnt[c]--;
      if (used[c]) {
        continue;
      }

      // "big" char insert first, we pop them out
      // when there are still same char outthere, so
      // we can insert them latter
      while (!ret.empty() && ret.back() > c && cnt[ret.back()] > 0) {
        used[ret.back()] = false;
        ret.pop_back();
      }

      used[c] = true;
      ret.push_back(c);
    }

    return ret;
  }
};

