#include "xxx.h"

class Solution {
public:
  bool isTransformable(string s, string t) {
    vector<vector<int>> idx(10);
    vector<int> pos(10, 0);
    for (int i = 0; i < s.size(); ++i) {
      idx[s[i] - '0'].push_back(i);
    }
    for (auto ch : t) {
      int d = ch - '0';
      if (pos[d] >= idx[d].size()) {
        return false;
      }
      for (int i = 0; i < d; ++i) {
        if (pos[i] < idx[i].size() && idx[i][pos[i]] < idx[d][pos[d]]) {
          return false;
        }
      }
      ++pos[d];
    }
    return true;
  }
};
