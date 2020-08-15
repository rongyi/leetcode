// https://leetcode.com/problems/peak-index-in-a-mountain-array/description/

#include "xxx.h"
class Solution {
public:
  int peakIndexInMountainArray(vector<int> &A) {
    const int n = A.size();
    vector<int> lmax(n, -1);
    vector<int> rmax(n, -1);
    for (int i = 1; i < n; ++i) {
      lmax[i] = max(lmax[i -1], A[i - 1]);
    }

    for (int i = n - 2; i >= 0; --i) {
      rmax[i] = max(rmax[i + 1], A[i + 1]);
    }
    for (int i = 0; i < n; ++i) {
      if (A[i] > lmax[i] && A[i] > rmax[i]) {
        return i;
      }
    }
    return -1;
  }
};
