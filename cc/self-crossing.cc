// http://leetcode.com/problems/self-crossing/description/
#include "xxx.hpp"

class Solution {
public:
  // https://leetcode.com/problems/self-crossing/solutions/729133/how-to-explain-to-interviewer-335-self-crossing/
  bool isSelfCrossing(vector<int> &x) {
    int sz = x.size();
    for (int i = 3; i < sz; i++) {
      if (i >= 3 && x[i] >= x[i - 2] && x[i - 1] <= x[i - 3]) {
        return true;
      }
      if (i >= 4 && x[i - 1] == x[i - 3] && x[i] + x[i - 4] >= x[i - 2]) {
        return true;
      }
      if (i >= 5 && x[i - 2] >= x[i - 4] && x[i - 5] + x[i - 1] >= x[i - 3] &&
          x[i - 1] <= x[i - 3] && x[i - 4] + x[i] >= x[i - 2]) {
        return true;
      }
    }

    return false;
  }
};

class SolutionTLE {
public:
  bool isSelfCrossing(vector<int> &x) {
    // 1. heading north x+1
    // 2. to west: y-1
    // 3. to south: x+1
    // 4. to east: y+1
    vector<vector<int>> directions{{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    set<pair<int, int>> cache;
    // we are at (0, 0) initially
    pair<int, int> end{0, 0};
    cache.insert(end);

    for (int i = 0; i < x.size(); i++) {
      int nextx = end.first;
      int nexty = end.second;
      for (int j = 0; j < x[i]; j++) {
        nextx += directions[i % 4][0];
        nexty += directions[i % 4][1];
        pair<int, int> npoint{nextx, nexty};

        if (cache.find(npoint) == cache.end()) {
          cache.insert(npoint);
        } else {
          return true;
        }
        end = npoint;
      }
    }

    return false;
  }
};
