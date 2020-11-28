// http://leetcode.com/problems/shuffle-string/description/
#include "xxx.h"

class Solution {
public:
  string restoreString(string s, vector<int> &indices) {
    vector<pair<int, int>> with_idx;

    for (int i = 0; i < indices.size(); ++i) {
      with_idx.push_back({indices[i], i});
    }
    sort(with_idx.begin(), with_idx.end());
    string ret;
    for (int i = 0; i < with_idx.size(); ++i) {
      ret.push_back(s[with_idx[i].second]);
    }
    return ret;
  }
};
