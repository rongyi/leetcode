// https://leetcode.com/problems/sliding-puzzle/description/
#include "one.h"

class Solution {
public:
  int slidingPuzzle(vector<vector<int>> &board) {
    vector<vector<int>> dirs{{1, 3}, {0, 2, 4}, {1, 5},
                             {0, 4}, {1, 3, 5}, {2, 4}};
    const string target = "123450";
    const int m = board.size();
    const int n = board[0].size();

    string start{""};
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        start += to_string(board[i][j]);
      }
    }

    queue<string> q{{start}};
    unordered_set<string> visited{start};
    int ret = 0;
    while (!q.empty()) {
      for (int i = q.size() - 1; i >= 0; --i) {
        auto cur = q.front();
        q.pop();
        // we found it!
        if (cur == target) {
          return ret;
        }
        // fuck, using bfs to search all
        auto zero_idx = cur.find("0");
        for (auto dir : dirs[zero_idx]) {
          auto cp = cur;
          swap(cp[dir], cp[zero_idx]);
          // fresh new possible layout
          if (visited.find(cp) == visited.end()) {
            visited.insert(cp);
            q.push(cp);
          }
        }
      }
      ++ret;
    }
    return -1;
  }
};
