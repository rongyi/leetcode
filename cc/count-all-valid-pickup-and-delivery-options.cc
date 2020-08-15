// http://leetcode.com/problems/count-all-valid-pickup-and-delivery-options/description/
#include "xxx.h"

class Solution {
public:
  // 假设 n - 1pair已经排好现在来排最后的两个p和d
  // p可以插入的位置有 2 * (n - 1) + 1 ==> 2n - 1
  // d可以插入的位置由 (2*(n - 1) + 1) + 1 ==> 2n
  // 然后p要在前，除以2少一半
  int countOrders(int n) {
    long ret = 1;
    const long mod = pow(10, 9) + 7;
    for (int i = 1; i <= n; i++) {
      ret = ret * (i * 2 - 1) * i % mod;
    }
    return ret;
  }
};
