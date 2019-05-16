// http://leetcode.com/problems/cracking-the-safe/description/
#include "xxx.h"

class Solution {
public:
  // https://leetcode.com/problems/cracking-the-safe/discuss/248621/C%2B%2B-dfs-to-find-Eulerian-Circle
  // TODO: 懵逼
  string crackSafe(int n, int k) {
    int len = (int)pow(k, n - 1);
    vector<vector<bool>> visited(len, vector<bool>(k, false));

    string ret{};
    dfs(visited, ret, len, k, 0);
    return ret + string(n - 1, '0');
  }

  void dfs(vector<vector<bool>> &visited, string &ret, int len, int k,
           int node) {
    for (int i = 0; i < k; i++) {
      if (!visited[node][i]) {
        visited[node][i] = true;
        dfs(visited, ret, len, k, (node * k + i) % len);
        ret += '0' + i;
      }
    }
  }
};
