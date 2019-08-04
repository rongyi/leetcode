// http://leetcode.com/problems/max-consecutive-ones-iii/description/
#include "xxx.h"

class Solution {
public:
  int longestOnes(vector<int> &A, int K) {
    const int n = A.size();
    int ret = 0;
    int start = 0;
    int cur_flips = 0;
    for (int i = 0; i < n; i++) {
      cur_flips += 1 - A[i];
      while (cur_flips > K) {
        if (A[start++] == 0) {
          --cur_flips;
        }
      }
      ret = max(ret, i - start + 1);
    }

    return ret;
  }
};
