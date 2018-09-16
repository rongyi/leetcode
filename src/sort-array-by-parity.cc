// https://leetcode.com/problems/sort-array-by-parity/description/
#include "one.h"
class Solution {
public:
  vector<int> sortArrayByParity(vector<int> &A) {
    const int n = A.size();
    int i = 0;
    int j = n - 1;
    vector<int> ret(n, 0);
    for (auto cur : A) {
      if (cur & 1) {
        ret[j--] = cur;
      } else {
        ret[i++] = cur;
      }
    }

    return ret;
  }
};
