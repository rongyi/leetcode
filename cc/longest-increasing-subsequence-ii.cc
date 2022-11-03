// https://leetcode.com/problems/longest-increasing-subsequence-ii/
#include "xxx.hpp"

class Solution {
public:
  // query range [ql, qr] in range [l, r], which start is start
  int query(int ql, int qr, int parent, int l, int r) {
    if (l > qr || r < ql) {
      return 0;
    }
    if (l >= ql && r <= qr) {
      return seg_[parent];
    }
    int mid = l + (r - l) / 2;
    return max(query(ql, qr, parent * 2 + 1, l, mid),
               query(ql, qr, parent * 2 + 2, mid + 1, r));
  }
  void update(int idx, int val, int parent, int l, int r) {
    if (l == r) {
      seg_[parent] = val;
      return;
    }
    int mid = l + (r - l) / 2;
    if (idx <= mid) {
      update(idx, val, parent * 2 + 1, l, mid);
    } else {
      update(idx, val, parent * 2 + 2, mid + 1, r);
    }
    seg_[parent] = max(seg_[2 * parent + 1], seg_[2 * parent + 2]);
  }
  // use segment tree
  int lengthOfLIS(vector<int> &nums, int k) {
    int x = 1;
    while (x <= 1e5) {
      x *= 2;
    }
    seg_.resize(2 * x, 0);

    int ret = 1;
    for (int i = 0; i < nums.size(); ++i) {
      int left = max(0, nums[i] - k);
      int right = nums[i] - 1;
      int q = query(left, right, 0, 0, x - 1);
      ret = max(ret, q + 1);
      update(nums[i], q + 1, 0, 0, x - 1);
    }

    return ret;
  }

private:
  vector<int> seg_;
};
