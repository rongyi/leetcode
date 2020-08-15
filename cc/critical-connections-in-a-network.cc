// http://leetcode.com/problems/critical-connections-in-a-network/description/
#include "xxx.h"

class Solution {
public:
  // https://www.hackerearth.com/zh/practice/notes/nj/
  // https://leetcode.com/problems/critical-connections-in-a-network/discuss/382386/C%2B%2B-DFS-O(n)-with-explanation
  vector<vector<int>> criticalConnections(int n,
                                          vector<vector<int>> &connections) {
    edges_.resize(n);
    visited_.resize(n, false);
    dist_.resize(n, numeric_limits<int>::max());
    low_.resize(n, numeric_limits<int>::max());

    for (int i = 0; i < connections.size(); ++i) {
      edges_[connections[i][0]].push_back(connections[i][1]);
      edges_[connections[i][1]].push_back(connections[i][0]);
    }

    for (int i = 0; i < n; ++i) {
      if (!visited_[i]) {
        dfs(i, -1);
      }
    }
    return ret_;
  }

private:
  void dfs(int u, int parent) {
    static int tim = 1;
    dist_[u] = low_[u] = tim++;
    int child = 0;
    visited_[u] = true;
    for (auto neib : edges_[u]) {
      if (!visited_[neib]) {
        child++;
        dfs(neib, u);
        low_[u] = min(low_[u], low_[neib]);
        // 不存在back_edge因为不存在两条对等边，所以这里的条件是 >
        if (low_[neib] > dist_[u]) {
          ret_.push_back({u, neib});
        }
      } else if (neib != parent) {
        // 那么存在back edge，翘上去的那种
        low_[u] = min(low_[u], dist_[neib]);
      }
    }
  }

private:
  // [0, [1, 2, 3]] ==> 节点0后面的邻接点有 1 2 3
  vector<vector<int>> edges_;
  // 最终输出结果
  vector<vector<int>> ret_;
  // 标记是否访问过
  vector<bool> visited_;
  // 在dfs访问过程中的链序号，越大说明从根节点来越深
  vector<int> dist_;
  // low_[i] ==> 表示从 i节点能到达的最低高度在其父节点被拿掉的情况下
  // "what is lowest level vertex ,x can climb to, in case its parent is removed
  // from the graph"
  vector<int> low_;
};
