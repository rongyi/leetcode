// http://leetcode.com/problems/shortest-bridge/description/
#include "xxx.hpp"

class Solution {
public:
  int shortestBridge(vector<vector<int>> &A) {
    m_ = A.size();
    n_ = A[0].size();

    vector<pair<int, int>> islands1;
    vector<pair<int, int>> islands2;

    bool first_done = false;
    for (int i = 0; i < m_; i++) {
      for (int j = 0; j < n_; j++) {
        if (A[i][j] == 1) {
          if (!first_done) {
            dfs(A, i, j, islands1);
            first_done = true;
          } else {
            dfs(A, i, j, islands2);
          }
        }
      }
    }

    int ret = numeric_limits<int>::max();
    // cout << islands1.size() << "    " << islands2.size() << endl;
    for (auto n1 : islands1) {
      for (auto n2 : islands2) {
        auto manhattan = abs(n1.first - n2.first) + abs(n1.second - n2.second);
        ret = min(ret, manhattan);
      }
    }

    return ret - 1;
  }

private:
  void dfs(vector<vector<int>> &A, int i, int j,
           vector<pair<int, int>> &node_list) {
    if (i < 0 || i >= m_ || j < 0 || j >= n_ || (A[i][j] == 0)) {
      return;
    }
    node_list.push_back({i, j});
    // clear this bit, so
    // when for loop see another 1, it is definitely in a second island
    A[i][j] = 0;

    dfs(A, i + 1, j, node_list);
    dfs(A, i - 1, j, node_list);
    dfs(A, i, j - 1, node_list);
    dfs(A, i, j + 1, node_list);
  }

private:
  int m_;
  int n_;
};
