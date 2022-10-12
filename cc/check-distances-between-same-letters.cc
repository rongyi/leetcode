// https://leetcode.com/problems/check-distances-between-same-letters/
#include "xxx.hpp"

class Solution {
public:
  bool checkDistances(string s, vector<int> &distance) {
    int sz = s.size();
    vector<int> cal(26, -1);
    for (int i = 0; i < sz; ++i) {
      if (cal[s[i] - 'a'] == -1) {
        cal[s[i] - 'a'] = i;
      } else {
        int calced = i - cal[s[i] - 'a'] - 1;
        if (calced != distance[s[i] - 'a']) {
          return false;
        }
      }
    }

    return true;
  }
};
