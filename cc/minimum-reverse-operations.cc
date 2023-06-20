// https://leetcode.com/problems/minimum-reverse-operations/
#include "xxx.hpp"

class Solution {
public:
  // https://leetcode.com/problems/minimum-reverse-operations/solutions/3370879/c-using-bfs-and-set-o-nlogn-100-100-for-the-moment/
  vector<int> minReverseOperations(int n, int p, vector<int> &banned, int k) {
    // for postion i in given subarray of length k
    // it's left most position is:
    // max(0, i - k + 1)
    // right most postion for start point
    // min(n - k, i)
    vector<int> banflag(n, false);
    for (auto &b : banned) {
      banflag[b] = true;
    }
    vector<int> ret(n, -1);
    // initial point
    ret[p] = 0;
    // no way to change
    if (k == 1) {
      return ret;
    }
    vector<set<int>> odd_even_sets(2);
    for (int i = 0; i < n; i++) {
      if (!banflag[i]) {
        odd_even_sets[i & 1].insert(i);
      }
    }
    odd_even_sets[p & 1].erase(p);
    // {idx, operation count}
    queue<pair<int, int>> q;
    q.push({p, 0});

    while (!q.empty()) {
      auto cur = q.front();
      q.pop();
      int i = cur.first;
      int ops = cur.second;
      int l = 2 * max(0, i - k + 1) + k - 1 - i;
      int r = 2 * min(n - k, i) + k - 1 - i;
      set<int> &refset = odd_even_sets[l & 1];
      for (auto it = refset.lower_bound(l); it != refset.end() && *it <= r;) {
        q.push({*it, ops + 1});
        ret[*it] = ops + 1;
        refset.erase(it++);
      }
    }

    return ret;
  }
};
