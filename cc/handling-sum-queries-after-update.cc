// https://leetcode.com/problems/handling-sum-queries-after-update/
#include "xxx.hpp"

class Solution {
public:
  vector<long long> handleQuery(vector<int> &nums1, vector<int> &nums2,
                                vector<vector<int>> &queries) {
    long long sum = accumulate(nums2.begin(), nums2.end(), 0ll);
    int sz = nums1.size();
    build(nums1, 1, 0, sz - 1);

    vector<long long> ret;
    for (auto &q : queries) {
      if (q[0] == 1) {
        update_tree(1, 0, sz - 1, q[1], q[2]);
      } else if (q[0] == 2) {
        sum += (long long)tree_[1] * q[1];
      } else {
        ret.push_back(sum);
      }
    }
    return ret;
  }

private:
  int build(vector<int> &arr, int n, int l, int r) {
    if (l == r) {
      tree_[n] = arr[l];

      return tree_[n];
    }
    tree_[n] = build(arr, 2 * n, l, (l + r) / 2) +
               build(arr, 2 * n + 1, (l + r) / 2 + 1, r);

    return tree_[n];
  }

  int update_tree(int n, int l, int r, int i, int j) {
    // outside
    if (r < i || l > j) {
      return lazy_[n] ? r - l + 1 - tree_[n] : tree_[n];
    }
    if (lazy_[n]) {
      tree_[n] = r - l + 1 - tree_[n];
      if (l != r) {
        lazy_[n * 2] = !lazy_[n * 2];
        lazy_[n * 2 + 1] = !lazy_[n * 2 + 1];
      }
      lazy_[n] = 0;
    }
    // inside
    if (l >= i && r <= j) {
      if (l != r) {
        lazy_[n * 2] = !lazy_[n * 2];
        lazy_[n * 2 + 1] = !lazy_[n * 2 + 1];
      }
      return tree_[n] = r - l + 1 - tree_[n];
    }
    tree_[n] = update_tree(n * 2, l, (l + r) / 2, i, j) +
               update_tree(n * 2 + 1, (l + r) / 2 + 1, r, i, j);

    return tree_[n];
  }

private:
  int tree_[400000] = {};
  int lazy_[400000] = {};
};
