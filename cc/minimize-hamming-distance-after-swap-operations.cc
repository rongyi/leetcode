// http://leetcode.com/problems/minimize-hamming-distance-after-swap-operations/description/
#include "xxx.h"

class Solution {
public:
  int minimumHammingDistance(vector<int> &source, vector<int> &target,
                             vector<vector<int>> &allowedSwaps) {
    const int n = source.size();
    vector<int> uf(n, -1);
    for (auto &a : allowedSwaps) {
      auto i = find(uf, a[0]);
      auto j = find(uf, a[1]);
      // merge to one
      if (i != j) {
        // 放的是负数，所以判断那个集合大
        if (uf[i] > uf[j]) {
          swap(i, j);
        }
        uf[i] += uf[j];
        uf[j] = i;
      }
    }

    int diff = 0;
    // 防止重复数据
    vector<unordered_multiset<int>> cycles(n);

    for (int i = 0; i < n; ++i) {
      if (source[i] != target[i]) {
        // 当前index所在的集合里都放一起
        cycles[find(uf, i)].insert(source[i]);
      }
    }

    for (int i = 0; i < n; ++i) {
      if (source[i] != target[i]) {
        auto &cur = cycles[find(uf, i)];
        auto it = cur.find(target[i]);
        if (it == cur.end()) {
          diff++;
        } else {
          cur.erase(it);
        }
      }
    }

    return diff;
  }

private:
  int find(vector<int> &lst, int i) {
    if (lst[i] < 0) {
      return i;
    }
    lst[i] = find(lst, lst[i]);

    return lst[i];
  }
};
