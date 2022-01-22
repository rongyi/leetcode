// http://leetcode.com/problems/split-a-string-into-the-max-number-of-unique-substrings/description/
#include "xxx.hpp"

class Solution {
public:
  // simple dfs will do
  int maxUniqueSplit(string s, int cur = 0) {
    if (cur == s.size()) {
      return 0;
    }
    int ret = -1;
    for (int sz = 1; cur + sz <= s.size(); ++sz) {
      auto it = cuts_.insert(s.substr(cur, sz));
      if (it.second) {
        int n_ret = maxUniqueSplit(s, cur + sz);
        if (n_ret != -1) {
          ret = max(ret, 1 + n_ret);
        }
        cuts_.erase(it.first);
      }
    }

    return ret;
  }

private:
  unordered_set<string> cuts_;
};
