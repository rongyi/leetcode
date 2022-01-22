// http://leetcode.com/problems/similar-string-groups/description/
#include "xxx.hpp"

namespace lc {
class disjoint_set {
public:
  disjoint_set(int n) { makeset(n); }
  void makeset(int n) {
    v_.resize(n);
    iota(v_.begin(), v_.end(), 0);
    size_ = n;
  }

  int find(int i) {
    if (i != v_[i]) {
      v_[i] = find(v_[i]);
    }
    return v_[i];
  }
  int size() { return size_; }

  void join(int i, int j) {
    int ri = find(i);
    int rj = find(j);
    if (ri != rj) {
      v_[ri] = rj;
      size_--;
    }
  }

private:
  vector<int> v_;
  int size_;
};
} // namespace lc

class Solution {
public:
  int numSimilarGroups(vector<string> &A) {
    lc::disjoint_set ds(A.size());
    for (int i = 0; i < A.size(); i++) {
      for (int j = i + 1; j < A.size(); j++) {
        if (similar(A[i], A[j])) {
          ds.join(i, j);
        }
      }
    }
    return ds.size();
  }

private:
  bool similar(string &a, string &b) {
    int diff = 0;
    for (int i = 0; i < a.size(); i++) {
      if (a[i] != b[i]) {
        diff++;
        if (diff > 2) {
          return false;
        }
      }
    }
    return true;
  }
};
