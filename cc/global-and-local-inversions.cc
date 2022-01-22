// http://www.lintcode.com/zh-cn/problem/global-and-local-inversions

#include "xxx.hpp"

class Solution {
public:
  bool isIdealPermutation(vector<int> &A) {
    const int n = A.size();
    int cur_min = numeric_limits<int>::max();
    for (int i = n - 1; i >= 2; --i) {
      cur_min = min(cur_min, A[i]);
      if (A[i - 2] > cur_min) {
        return false;
      }
    }
    return true;
  }
};
