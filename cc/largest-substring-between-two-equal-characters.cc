// http://leetcode.com/problems/largest-substring-between-two-equal-characters/description/
#include "xxx.h"

class Solution {
public:
  int maxLengthBetweenEqualCharacters(string s) {
    vector<vector<int>> dists(26);
    for (int i = 0; i < s.size(); ++i) {
      dists[s[i] - 'a'].push_back(i);
    }
    int max_len = 0;
    bool all_uniq = true;
    for (auto &lst : dists) {
      if (lst.size() < 2) {
        continue;
      }
      all_uniq = false;
      max_len = max(max_len, lst.back() - lst.front() - 1);
    }

    if (all_uniq) {
      return -1;
    }
    return max_len;
  }
};
