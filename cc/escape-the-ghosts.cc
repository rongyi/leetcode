// http://leetcode.com/problems/escape-the-ghosts/description/
#include "xxx.hpp"
class Solution {
public:
  bool escapeGhosts(vector<vector<int>> &ghosts, vector<int> &target) {
    const int dist = abs(target[0]) + abs(target[1]);
    for (auto g : ghosts) {
      int t = abs(g[0] - target[0]) + abs(g[1] - target[1]);
      if (t <= dist) {
        return false;
      }
    }
    return true;
  }
};
