// http://leetcode.com/problems/beautiful-arrangement/description/
#include "xxx.hpp"

class Solution {
public:
  int countArrangement(int n) {
    int ret = 0;
    vector<bool> visited(n + 1, false);
    vector<int> cur;
    dfs(n, cur, visited, ret);

    return ret;
  }

  void dfs(int n, vector<int> &cur, vector<bool> &visited, int &ret) {
    if (cur.size() == n) {
      ++ret;
      return;
    }
    // the i-th value, first is 1
    int l = cur.size() + 1;
    // total value
    for (int i = 1; i <= n; ++i) {
      // the value on this position can be put on
      if (!visited[i] && ((l % i == 0 || i % l == 0))) {
        visited[i] = true;
        cur.push_back(i);
        dfs(n, cur, visited, ret);

        visited[i] = false;
        cur.pop_back();
      }
    }
  }
};
