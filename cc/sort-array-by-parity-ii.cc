// http://leetcode.com/problems/sort-array-by-parity-ii/description/
#include "xxx.hpp"

class Solution {
public:
  vector<int> sortArrayByParityII(vector<int> &A) {
    const int n = A.size();
    int i = 0;
    int j = n - 1;
    while (i < n && j >= 0) {
      for (; i < n && (A[i] % 2 == 0); i += 2)
        ;
      for (; j >= 0 && (A[j] % 2 == 1); j -= 2)
        ;
      if (i < n && j >= 0) {
        swap(A[i], A[j]);
        i += 2;
        j -= 2;
      }
    }
    return A;
  }
};
