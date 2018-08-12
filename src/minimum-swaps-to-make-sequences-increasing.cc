// https://leetcode.com/problems/minimum-swaps-to-make-sequences-increasing/description/
#include "one.h"

class Solution {
public:
  // 递推公式有点相对运动的感觉
  // 1. 用两个数组swap, noswap，swap[i] 表示数组有序，且当前节点i需要互换，noswap表示不需要置换i节点
  // swap[0] == 1 because it need swap
  // noswap[0] == 0


  int minSwap(vector<int> &a, vector<int> &b) {
    const int n = a.size();
    vector<int> swap(n, n);
    vector<int> noswap(n, n);
    swap[0]= 1;
    noswap[0] = 0;

    for (int i = 1; i < n; ++i) {
      if (a[i] > a[i - 1] && b[i] > b[i - 1]) {
        swap[i] = swap[i - 1] + 1;
        noswap[i] = noswap[i - 1];
      }

      if (a[i] > b[i - 1] && b[i] > a[i - 1]) {
        swap[i] = min(swap[i] , noswap[i - 1] + 1);
        noswap[i] = min(noswap[i], swap[i - 1]);
      }
    }

    return min(swap[n - 1], noswap[n - 1]);
  }
};
