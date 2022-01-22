// http://leetcode.com/problems/sum-of-subsequence-widths/description/
#include "xxx.hpp"

class Solution {
public:
  int sumSubseqWidths(vector<int> &A) {
    long c = 1;
    long ret = 0;
    long mod = pow(10, 9) + 7;
    // For A[i]:
    // There are i smaller numbers,
    // so there are 2 ^ i sequences in which A[i] is maximum.
    // we should do res += A[i] * (2 ^ i)

    // There are n - i - 1 bigger numbers,
    // so there are 2 ^ (n - i - 1) sequences in which A[i] is minimum.
    // we should do res -= A[i] * 2 ^ (n - i - 1)

    sort(A.begin(), A.end());
    for (int i = 0; i < A.size(); ++i, c = (c << 1) % mod) {
      ret = (ret + A[i] * c - A[A.size() - i - 1] * c) % mod;
    }
    return (ret + mod) % mod;
  }
};
