// http://leetcode.com/problems/time-needed-to-inform-all-employees/description/
#include "xxx.h"

class Solution {
public:
  int numOfMinutes(int n, int headID, vector<int> &manager,
                   vector<int> &informTime) {
    // manager and it's managee
    unordered_map<int, vector<int>> level;
    for (int i = 0; i < n; ++i) {
      level[manager[i]].push_back(i);
    }

    return dfs(level, headID, informTime);
  }

private:
  // dfs 加上每一层最大的那个
  int dfs(unordered_map<int, vector<int>> &level, int start, vector<int> &it) {
    int mx = 0;
    if (level.count(start)) {
      for (auto &empl : level[start]) {
        mx = max(mx, dfs(level, empl, it));
      }
    }

    return it[start] + mx;
  }
};
