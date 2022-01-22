// http://leetcode.com/problems/number-of-squareful-arrays/description/
#include "xxx.hpp"

class Solution {
public:
  // https://leetcode.com/problems/number-of-squareful-arrays/discuss/238612/4msC%2B%2B-Simple-Backtracking-like-Permutations-II
  int numSquarefulPerms(vector<int> &A) {
    sort(A.begin(), A.end());
    int ret = 0;
    dfs(A, 0, ret);
    return ret;
  }
  void dfs(vector<int> A, int cur_idx, int &ret) {
    if (cur_idx >= A.size()) {
      ++ret;
    }
    for (int i = cur_idx; i < A.size(); i++) {
      if (i > cur_idx && A[i] == A[cur_idx]) {
        continue;
      }
      swap(A[i], A[cur_idx]);
      if ((cur_idx == 0) || (cur_idx > 0 && isSquare(A[cur_idx] + A[cur_idx - 1]))) {
        dfs(A, cur_idx + 1, ret);
      }
    }
  }
  bool isSquare(int v) {
    int r = sqrt(v);
    return r * r == v;
  }
};
