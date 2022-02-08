// https://leetcode.com/problems/two-furthest-houses-with-different-colors/
#include "xxx.hpp"

class Solution {
public:
  int maxDistance(vector<int> &colors) {
    map<int, vector<int>> group_colors;
    // for each color, mark its first and last pos
    for (int i = 0; i < colors.size(); ++i) {
      group_colors[colors[i]].push_back(i);
    }
    int ret = 0;
    // max color is left most color - right most color
    for (auto &kv : group_colors) {
      for (auto &kv2 : group_colors) {
        if (kv.first == kv2.first) {
          continue;
        }
        ret = max(ret, abs(kv.second.front() - kv2.second.back()));
      }
    }

    return ret;
  }
};
