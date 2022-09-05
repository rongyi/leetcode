// https://leetcode.com/problems/shifting-letters-ii/
#include "xxx.hpp"

class Solution {
public:
  string shiftingLetters(string s, vector<vector<int>> &shifts) {
    int sz = s.size();
    vector<int> acc(sz + 1, 0);

    for (auto &st : shifts) {
      auto l = st[0];
      auto r = st[1];
      if (st[2] == 0) {
        acc[l]--;
        acc[r + 1]++;
      } else {
        acc[l]++;
        acc[r + 1]--;
      }
    }
    string ret;
    int cur_acc = 0;
    for (int i = 0; i < sz; ++i) {
      cur_acc += acc[i];
      int k = (cur_acc + 26) % 26;
      char cur = 'a' + (s[i] - 'a' + k + 26) % 26;
      ret.push_back(cur);
    }

    return ret;
  }
};
