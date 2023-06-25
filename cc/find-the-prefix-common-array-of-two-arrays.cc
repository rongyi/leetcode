// https://leetcode.com/problems/find-the-prefix-common-array-of-two-arrays/
#include "xxx.hpp"

class Solution {
public:
  vector<int> findThePrefixCommonArray(vector<int> &A, vector<int> &B) {
    set<int> sa;
    set<int> sb;
    int sz = A.size();
    auto same = [&]() -> int {
      int ret = 0;
      for (auto &i : sa) {
        if (sb.count(i)) {
          ret++;
        }
      }
      return ret;
    };
    vector<int> ret(sz, 0);
    for (int i = 0; i < sz; i++) {
      sa.insert(A[i]);
      sb.insert(B[i]);
      ret[i] = same();
    }

    return ret;
  }
};
