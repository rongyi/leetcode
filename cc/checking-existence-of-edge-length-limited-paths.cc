// http://leetcode.com/problems/checking-existence-of-edge-length-limited-paths/description/
#include "xxx.h"
class Solution {
public:
  vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>> &es,
                                         vector<vector<int>> &qs) {
    vector<bool> ret(qs.size(), false);
    // 带上index
    for (int i = 0; i < qs.size(); ++i) {
      qs[i].push_back(i);
    }

    sort(es.begin(), es.end(), [](auto &i, auto &j) { return i[2] < j[2]; });
    sort(qs.begin(), qs.end(), [](auto &i, auto &j) { return i[2] < j[2]; });

    UnionFind uf(n);
    int i = 0;
    for (auto q : qs) {
      auto u = q[0];
      auto v = q[1];
      auto limit = q[2];
      auto idx = q[3];
      // 把符合limit要求的都串起来
      for (; i < es.size() && es[i][2] < limit; ++i) {
        uf.connect(es[i][0], es[i][1]);
      }
      // 能串的都串起来，这下来看这时候的图如何？
      ret[idx] = uf.connected(u, v);
    }

    return ret;
  }

private:
  class UnionFind {
    vector<int> id;

  public:
    UnionFind(int n) : id(n) { iota(begin(id), end(id), 0); }
    // lazy connect
    void connect(int a, int b) {
      int x = find(a), y = find(b);
      if (x == y)
        return;
      id[x] = y;
    }
    bool connected(int i, int j) { return find(i) == find(j); }
    int find(int a) { return id[a] == a ? a : (id[a] = find(id[a])); }
  };
};

int main() {
  Solution so;
  vector<vector<int>> e{{0, 1, 10}, {1, 2, 5}, {2, 3, 9}, {3, 4, 13}};
  vector<vector<int>> q{{0, 4, 14}, {1, 4, 13}};
  so.distanceLimitedPathsExist(5, e, q);
}
