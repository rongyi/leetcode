// http://leetcode.com/problems/longest-common-prefix/description/
#include "xxx.hpp"

class Solution {
public:
  string longestCommonPrefix(vector<string> &ss) {
    int min_len = numeric_limits<int>::max();
    for (auto &s : ss) {
      min_len = min(min_len, (int)s.size());
    }
    int j = 0;
    for (; j < min_len; ++j) {
      for (int i = 1; i < ss.size(); ++i) {
        if (ss[i][j] != ss[0][j]) {
          return ss[i].substr(0, j);
        }
      }
    }
    return ss[0].substr(0, j);
  }
};

