// http://leetcode.com/problems/graph-connectivity-with-threshold/description/
#include "xxx.h"

class Solution {
public:
  vector<bool> areConnected(int n, int threshold,
                            vector<vector<int>> &queries) {
    vector<int> ds(n + 1, -1);
    // strictly greater
    // 把这个取件所有可以相乘的数都找出来，for循环的参数也是很妙的
    for (int i = threshold + 1; 2 * i <= n; ++i) {
      if (ds[i] != -1) {
        continue;
      }
      int p1 = i;
      for (int j = 2 * i; j <= n; j += i) {
        int p2 = find(ds, j);
        if (p1 != p2) {
          // ensure p1 the smaller one
          if (ds[p1] > ds[p2]) {
            swap(p1, p2);
          }
          // union find 如果这里不理解请参考:
          // remove-max-number-of-edges-to-keep-graph-fully-traversable.cc:28
          ds[p1] += ds[p2];
          ds[p2] = p1;
        }
      }
    }
    vector<bool> ret;
    for (auto &q : queries) {
      ret.push_back(find(ds, q[0]) == find(ds, q[1]));
    }
    return ret;
  }

private:
  int find(vector<int> &ds, int i) {
    if (ds[i] < 0) {
      return i;
    }

    return ds[i] = find(ds, ds[i]);
  }
};
