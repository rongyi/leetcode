// http://leetcode.com/problems/redundant-connection-ii/description/
#include "xxx.h"


class Solution {
public:
  // 分析： 有两种情况：
  // 1. 一个环，所有node都只有一个parent
  // 2. 有个node有两个parent, 另外一个没有parent，可能有一个环也可能没有环
  // https://leetcode.com/problems/redundant-connection-ii/discuss/138593/C%2B%2B-very-straight-forward-solution-either-node-has-two-parents-no-parent
  vector<int> findRedundantDirectedConnection(vector<vector<int>> &edges) {

    vector<int> parent(edges.size() + 1, 0);
    vector<int> cycle = {0, 0};
    vector<bool> visited(edges.size(), false);

    int target = 0;
    int p1 = 0;
    int p2 = 0;
    for (auto e : edges) {
      if (visited[e[0]] && visited[e[1]]) {
        cycle = {e[0], e[1]};
      } else {
        visited[e[0]] = true;
        visited[e[1]] = true;
      }

      if (parent[e[1]] > 0) {
        target = e[1];
        p1 = parent[e[1]];
        p2 = e[0];
      } else {
        parent[e[1]] = e[0];
      }
    }

    if (target == 0) {
      // no double father node, must has circle;
      return cycle;
    } else {
      // if p1 is in a circle, then must remove p1 edge, otherwise, remove the
      // later one, p2
      while (p1 != target && parent[p1] > 0)
        p1 = parent[p1];
      if (p1 == target) {
        return {parent[target], target};
      } else {
        return {p2, target};
      }
    }
  }
};

int main() { Solution so; }
