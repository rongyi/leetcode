// https://leetcode.com/problems/minimum-swaps-to-make-sequences-increasing/description/
#include "xxx.h"

class Solution {
public:
  // 递推公式有点相对运动的感觉
  // 1. 用两个数组swap, noswap，swap[i] 表示数组有序，且当前节点i需要互换，noswap表示不需要置换i节点
  // swap[0] == 1 because it need swap
  // noswap[0] == 0


  // 如果当前节点和前一个节点在两个数组中都有序了，所以按道理不需要置换当前节点，所以 noswap[i] = noswap[i - 1]
  // 但如果非要强制转换，那之前的节点也得跟着换，所以swap[i] = swap[i - 1] + 1
  // 如果是置换当前节点后有序，则swap[i] = noswap[i - 1] + 1, 如果非要不换此节点（某种程度的相对运动）,那就换前一个节点，noswap[i] = swap[i - 1]
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
