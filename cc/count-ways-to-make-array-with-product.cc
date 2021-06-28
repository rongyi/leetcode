// http://leetcode.com/problems/count-ways-to-make-array-with-product/description/
#include "xxx.h"

class Solution {
public:
  vector<int> waysToFillArray(vector<vector<int>> &queries) {
    mod_ = 1e9 + 7;
    vector<int> ret;
    for (auto &q : queries) {
      cur_num_ = q[0];
      dp_.clear();
      long cur = cal(0, q[1]) % mod_;
      ret.push_back(cur);
    }

    return ret;
  }

private:
  long cal(int size, int prod) {
    if (dp_.find({size, prod}) != dp_.end()) {
      return dp_[{size, prod}];
    }
    if (size == cur_num_) {
      return dp_[{size, prod}] = (prod == 1);
    }
    if (prod == 1) {
      return dp_[{size, prod}] = comb(cur_num_, cur_num_ - size) % mod_;
    }
    long ret = 0;
    for (int v = 1; v * v <= prod; v++) {
      if (prod % v == 0) {
        if (v != 1) {
          ret = (ret % mod_ + cal(size + 1, prod / v) % mod_) % mod_;
        }
        if (v != prod / v) {
          ret = (ret % mod_ + cal(size + 1, v) % mod_) % mod_;
        }
      }
    }

    return dp_[{size, prod}] = ret % mod_;
  }

  //  k       k - 1        k
  // C   ==> C         + C
  //  m       m - 1        m - 1
  //         include     exclude
  // 包含一个特殊值与不包含这个特殊值两种情况
  long comb(int cur_num_, int k) {
    if (cp_.find({cur_num_, k}) != cp_.end()) {
      return cp_[{cur_num_, k}];
    }
    if (k > cur_num_) {
      return cp_[{cur_num_, k}] = 0;
    }
    if (k == 0 || k == cur_num_) {
      return cp_[{cur_num_, k}] = 1;
    }

    return cp_[{cur_num_, k}] = (comb(cur_num_ - 1, k - 1) % mod_ +
                                 comb(cur_num_ - 1, k) % mod_) %
                                mod_;
  }

private:
  int mod_;
  int cur_num_;
  map<pair<int, int>, int> cp_;
  map<pair<int, int>, int> dp_;
};
