// http://leetcode.com/problems/sum-of-distances-in-tree/description/
#include "xxx.h"

class Solution {
public:
  vector<int> sumOfDistancesInTree(int N, vector<vector<int>> &edges) {
    vector<vector<int>> g(N);
    for (auto e : edges) {
      g[e[0]].push_back(e[1]);
      g[e[1]].push_back(e[0]);
    }
    vector<pair<int, int>> nums_dis(N);
    vector<int> ret(N, -1);

    dfs(g, nums_dis, 0, -1);

    dfs2(g, nums_dis, ret, 0, -1, N);

    return ret;
  }

private:
  void dfs(vector<vector<int>> &g, vector<pair<int, int>> &num_dis, int cur,
           int pre) {
    int ret1 = 1;
    int ret2 = 0;
    for (int i = 0; i < g[cur].size(); i++) {
      int w = g[cur][i];
      if (w == pre) {
        continue;
      }
      dfs(g, num_dis, w, cur);
      // 节点多了这么多
      ret1 += num_dis[w].first;
      // x个节点已知的distance之和和y
      // 现在x作为结合‘挂’在了一个新的节点 y上，如下图
      //    y
      //   /
      //  x
      // 这样的化x已经数好的distance到y会全部多一跳， 总共多少？ 集合X的节点数
      // 公式就是以下
      ret2 += num_dis[w].first + num_dis[w].second;
    }

    num_dis[cur] = {ret1, ret2};
  }
  void dfs2(vector<vector<int>> &g, vector<pair<int, int>> &num_dis,
            vector<int> &ret, int k, int p, int N) {
    if (p == -1) {
      ret[k] = num_dis[k].second;
    } else {
      // https://leetcode.com/problems/sum-of-distances-in-tree/discuss/161975/My-DFS-sulotion-two-passes
      // (1) we divide the tree into two parts(two dotted circles).
      // (2) the total number of k subtree is num[k], and pis farther of k, the total number of p subtree except k subtree is N - num[k].
      // (3) assume we have calculated node p, now we should calculate node k, each node in k subtree should decrease by 1, and each node in p subtree except k subtree should increase by 1.
      // (4) so we get ans[k] = ans[p] - num[k] * 1 + (N - num[k]) * 1, which is ans[k] = ans[p] + N - 2 * num[k].
      ret[k] = ret[p] + N - 2 * num_dis[k].first;
    }
    for (int i = 0; i < g[k].size(); ++i) {
      int w = g[k][i];
      if (w != p) {
        dfs2(g, num_dis, ret, w, k, N);
      }
    }
  }
};

int main() {
  Solution so;
  vector<vector<int>> input{{0, 1}, {1, 2}};
  so.sumOfDistancesInTree(3, input);
}
