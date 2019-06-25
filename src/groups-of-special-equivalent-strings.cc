// http://leetcode.com/problems/groups-of-special-equivalent-strings/description/
#include "xxx.h"

class Solution {
public:
  int numSpecialEquivGroups(vector<string> &A) {
    unordered_set<string> same;

    for (auto &s : A) {
      string odd{};
      string even{};
      for (int i = 0; i < s.size(); i++) {
        if (i & 1) {
          odd.push_back(s[i]);
        } else {
          even.push_back(s[i]);
        }
      }
      sort(odd.begin(), odd.end());
      sort(even.begin(), even.end());
      same.insert(odd + even);
    }

    return same.size();
  }
};
