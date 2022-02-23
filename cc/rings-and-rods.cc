// https://leetcode.com/problems/rings-and-rods/
#include "xxx.hpp"

class Solution {
public:
  int countPoints(string rings) {
    array<set<char>, 10> cs;
    for (int i = 0; i < rings.size(); i += 2) {
      int idx = rings[i + 1] - '0';
      char color = rings[i];
      cs[idx].insert(color);
    }
    int ret = 0;
    for (int i = 0; i < 10; ++i) {
      if (cs[i].size() == 3) {
        ++ret;
      }
    }
    return ret;
  }
};
