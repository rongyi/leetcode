// https://leetcode.com/problems/booking-concert-tickets-in-groups/
#include "xxx.hpp"

class BookMyShow {
public:
  BookMyShow(int n, int m) : n_(n), m_(m) {
    int sz = 1;
    while (sz < n * 2) {
      sz <<= 1;
    }
    seg_tree_.resize(sz);
    build(0, 0, n - 1);
  }

  vector<int> gather(int k, int maxRow) {
    auto ret = query_max(0, 0, n_ - 1, k, maxRow);
    if (ret.size()) {
      update_max(0, 0, n_ - 1, ret[0], k);
    }
    return ret;
  }

  bool scatter(int k, int maxRow) {
    long long cnt = query_sum(0, 0, n_ - 1, maxRow);
    if (cnt >= k) {
      update_sum(0, 0, n_ - 1, k, maxRow);
      return true;
    }
    return false;
  }

private:
  void build(int i, int p, int q) {
    if (p == q) {
      seg_tree_[i] = {m_, m_};
      return;
    }
    int mid = (p + q) / 2;
    seg_tree_[i] = {m_, (long long)(q - p + 1) * m_};
    build(2 * i + 1, p, mid);
    build(2 * i + 2, mid + 1, q);
  }
  vector<int> query_max(int i, int p, int q, int k, int max_row) {
    if (p > max_row) {
      return {};
    }
    if (seg_tree_[i][0] < k) {
      return {};
    }
    if (p == q) {
      // the row and the first seat number
      return {p, (int)(m_ - seg_tree_[i][0])};
    }
    int mid = (p + q) / 2;
    vector<int> ret = query_max(2 * i + 1, p, mid, k, max_row);
    if (ret.size()) {
      return ret;
    }
    return query_max(2 * i + 2, mid + 1, q, k, max_row);
  }
  void update_max(int i, int p, int q, int row, int k) {
    if (p > row || q < row) {
      return;
    }
    if (p == q) {
      seg_tree_[i][0] -= k;
      seg_tree_[i][1] -= k;
      return;
    }
    int mid = (p + q) / 2;
    seg_tree_[i][1] -= k;

    update_max(2 * i + 1, p, mid, row, k);
    update_max(2 * i + 2, mid + 1, q, row, k);

    seg_tree_[i][0] = max(seg_tree_[2 * i + 1][0], seg_tree_[2 * i + 2][0]);
  }

  long long query_sum(int i, int p, int q, int max_row) {
    if (p > max_row) {
      return 0;
    }
    // in a single side
    if (q <= max_row) {
      return seg_tree_[i][1];
    }
    // else we need to search two side
    int mid = (p + q) / 2;
    return query_sum(2 * i + 1, p, mid, max_row) +
           query_sum(2 * i + 2, mid + 1, q, max_row);
  }
  void update_sum(int i, int p, int q, int k, int max_row) {
    if (p > max_row) {
      return;
    }
    if (p == q) {
      seg_tree_[i][0] -= k;
      seg_tree_[i][1] -= k;
      return;
    }
    int mid = (p + q) / 2;

    seg_tree_[i][1] -= k;

    // left side is enough
    if (mid + 1 > max_row || seg_tree_[2 * i + 1][1] >= k) {
      update_sum(2 * i + 1, p, mid, k, max_row);
    } else {
      // update left and the right side
      k -= seg_tree_[2 * i + 1][1];
      update_sum(2 * i + 1, p, mid, seg_tree_[2 * i + 1][1], max_row);
      update_sum(2 * i + 2, mid + 1, q, k, max_row);
    }

    seg_tree_[i][0] = max(seg_tree_[2 * i + 1][0], seg_tree_[2 * i + 2][0]);
  }

private:
  int n_;
  int m_;
  vector<array<long long, 2>> seg_tree_;
};

/**
 * Your BookMyShow object will be instantiated and called as such:
 * BookMyShow* obj = new BookMyShow(n, m);
 * vector<int> param_1 = obj->gather(k,maxRow);
 * bool param_2 = obj->scatter(k,maxRow);
 */
