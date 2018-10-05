#include "one.h"

class Solution {
public:
  void dfs(vector<vector<int>> &grid, int i, int j, vector<string> path) {
    const int m = grid.size();
    const int n = grid[0].size();
    if (i >= m || j >= n) {
      return;
    }
    stringstream ss;
    ss << "i: " << i << " j:" << j;
    path.push_back(ss.str());

    if (i == m - 1 && j == n - 1) {
      for (auto p : path) {
        cout << p << endl;
      }
      cout << "==========" << endl;
      return;
    }

    dfs(grid, i + 1, j, path);
    dfs(grid, i, j + 1, path);
  }
};

int main() {
  // Solution so;
  // vector<vector<int>> input{{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
  // vector<string> path;
  // so.dfs(input, 0, 0, path);

  unordered_map<int, int> test;
  test[1] = 1;
  for (int i = 0; i < 2; i++) {
    --test[i];
  }
  for (auto kv : test) {
    cout << kv.first << "--> " << kv.second << endl;
  }
}
