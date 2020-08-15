// http://leetcode.com/problems/minimum-number-of-k-consecutive-bit-flips/description/
#include "xxx.h"

class Solution {
public:
  int minKBitFlips(vector<int> &A, int K) {
    const int n = A.size();
    vector<int> flipped(n, 0);
    int cur_flip = 0;
    int ret = 0;

    for (int i = 0; i < n; i++) {
      if (i >= K) {
        cur_flip ^= flipped[i - K];
      }
      // Create a new array isFlipped[n].
      // isFlipped[i] = 1 iff we flip K consecutive bits starting at A[i].

      // We maintain a variable flipped and flipped = 1 iff the current bit is flipped.

      // If flipped = 0 and A[i] = 0, we need to flip at A[i].
      // If flipped = 1 and A[i] = 1, we need to flip at A[i].
      if (cur_flip == A[i]) {
        if (i + K > n) {
          return -1;
        }
        flipped[i] = 1;
        // 翻转当前标记位
        cur_flip ^= 1;
        ret++;
      }
    }

    return ret;
  }
};
