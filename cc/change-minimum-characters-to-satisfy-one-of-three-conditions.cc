// http://leetcode.com/problems/change-minimum-characters-to-satisfy-one-of-three-conditions/description/
#include "xxx.hpp"

class Solution {
public:
  // 也是被喷的题目
  int minCharacters(string a, string b) {
    auto m = min(mkABelowB(a, b), mkABelowB(b, a));
    return min(m, mkUniqSame(a, b));
  }

private:
  int mkABelowB(string &a, string &b) {
    int ret = numeric_limits<int>::max();
    for (int i = 1; i < 26; i++) {
      int cur = 0;
      for (auto &c : a) {
        if ((c - 'a') >= i) {
          cur++;
        }
      }
      for (auto &c : b) {
        if ((c - 'a') < i) {
          cur++;
        }
      }
      ret = min(ret, cur);
    }

    return ret;
  }
  int mkUniqSame(string &a, string &b) {
    vector<int> count(26, 0);
    for (auto &c : a) {
      count[c - 'a']++;
    }
    for (auto &c : b) {
      count[c - 'a']++;
    }
    int m = 0;
    for (int i = 0; i < 26; ++i) {
      m = max(m, count[i]);
    }

    return a.size() + b.size() - m;
  }
};
