// http://leetcode.com/problems/substring-with-concatenation-of-all-words/description/
#include "xxx.h"
class Solution {
public:
  vector<int> findSubstring(string s, vector<string> &words) {
    vector<int> ret;
    const int n = words.size();
    if (n == 0) {
      return ret;
    }
    const int m = words[0].size();
    const int len = s.size();
    unordered_map<string, int> cnt;
    for (auto &w : words) {
      ++cnt[w];
    }

    for (int i = 0; i <= len - n * m; ++i) {
      unordered_map<string, int> cur;
      int j = 0;
      for (; j < n; ++j) {
        auto tmp = s.substr(i + j * m, m);
        if (cnt.find(tmp) == cnt.end()) {
          break;
        }
        ++cur[tmp];
        if (cur[tmp] > cnt[tmp]) {
          break;
        }
      }
      if (j == n ) {
        ret.push_back(i);
      }
    }
    return ret;
  }
};
