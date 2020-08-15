// http://leetcode.com/problems/self-crossing/description/
#include "xxx.h"

class Solution {
public:
  bool isSelfCrossing(vector<int> &x) {
    vector<vector<int>> directions{{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    set<pair<int, int>> cache;
    pair<int, int> start{0, 0};
    cache.insert(start);

    for (int i = 0; i < x.size(); i++) {
      int nextx = start.first;
      int nexty = start.second;
      for (int j = 0; j < x[i]; j++) {
        nextx += directions[i % 4][0];
        nexty += directions[i % 4][1];
        pair<int, int> npoint{nextx, nexty};
        if (cache.find(npoint) == cache.end()) {
          cache.insert(npoint);
        } else {
          return true;
        }
        start = npoint;
      }
    }

    return false;
  }
};
int main() {
  Solution so;

}
