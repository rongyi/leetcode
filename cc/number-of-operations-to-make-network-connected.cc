// http://leetcode.com/problems/number-of-operations-to-make-network-connected/description/
#include "xxx.h"

class Solution {
public:
  int makeConnected(int n, vector<vector<int>> &connections) {
    // shortcut
    if (connections.size() < n - 1) {
      return -1;
    }
    vector<int> ds(n, -1);
    for (auto &c : connections) {
      auto i = find(ds, c[0]);
      auto j = find(ds, c[1]);
      if (i != j) {
        if (ds[j] < ds[i]) {
          swap(i, j);
        }
        ds[i] += ds[j];
        ds[j] = i;
        --n;
      }
    }
    return n - 1;
  }

private:
  int find(vector<int> &ds, int i) {
    if (ds[i] < 0) {
      return i;
    }

    ds[i] = find(ds, ds[i]);

    return ds[i];
  }
};

int main() {
  Solution so;
  vector<vector<int>> input{{0, 1}, {0, 2}, {1, 2}};
  so.makeConnected(4, input);
}
