// http://leetcode.com/problems/path-crossing/description/
#include "xxx.hpp"

class Solution {
public:
  bool isPathCrossing(string path) {
    set<pair<int, int>> cache;
    int x = 0;
    int y = 0;
    cache.insert({x, y});
    // 这是经过原点
    for (auto &p : path) {
      switch (p) {
      case 'N':
        y += 1;
        break;
      case 'S':
        y -= 1;
        break;
      case 'W':
        x -= 1;
        break;
      case 'E':
        x += 1;
        break;
      }

      if (cache.count({x, y})) {
        return true;
      }
      cache.insert({x, y});
    }
    return false;
  }
};
