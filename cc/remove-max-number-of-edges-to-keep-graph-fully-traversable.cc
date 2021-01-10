// http://leetcode.com/problems/remove-max-number-of-edges-to-keep-graph-fully-traversable/description/
#include "xxx.h"
class Solution {
public:
  int maxNumEdgesToRemove(int n, vector<vector<int>> &edges) {
    int used = 0;
    vector<int> ds_both(n + 1, -1);
    for (int type = 3; type > 0; --type) {
      auto ds_one = ds_both;
      auto &ds = type == 3 ? ds_both : ds_one;
      for (auto &e : edges) {
        if (e[0] == type) {
          int i = find(ds, e[1]);
          int j = find(ds, e[2]);
          if (i != j) {
            ++used;
            // ensure i the smaller one
            if (ds[i] > ds[j]) {
              swap(i, j);
            }
            // in top group node, we store the group size in there
            // 初始化都是-1, 加上去就是size的负数
            ds[i] += ds[j];
            ds[j] = i;
          }
        }
      }

      // 和上文groupsize对应
      if (type != 3 && ds[find(ds, 1)] != -n) {
        return -1;
      }
    }

    return edges.size() - used;
  }

private:
  int find(vector<int> &ds, int i) {
    // 否则就一直到parent
    return ds[i] < 0 ? i : ds[i] = find(ds, ds[i]);
  }
};
