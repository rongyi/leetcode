// http://leetcode.com/problems/fair-candy-swap/description/
#include "xxx.h"

class Solution {
public:
  vector<int> fairCandySwap(vector<int> &A, vector<int> &B) {
    // expect: suma - sumb = 0
    // actually: suma - sumb = x && x != 0
    // 不妨假设 A中swap a，B中swap b
    // suma这里最终效果会 -a + b
    // 再把前面的等式配一下
    // suma - x / 2 - (sumb + x / 2) = 0
    // -a + b = -(x / 2)
    // ==> a = b + (x / 2);
    int diff = accumulate(A.begin(), A.end(), 0) - accumulate(B.begin(), B.end(), 0);
    diff /= 2;
    unordered_set<int> seta(A.begin(), A.end());
    for (auto curb : B) {
      if (seta.count(curb+diff)) {
        return {curb+diff, curb};
      }
    }
    return {-1, -1};
  }
};
