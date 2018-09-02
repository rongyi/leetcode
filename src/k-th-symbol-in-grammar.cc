// https://leetcode.com/problems/k-th-symbol-in-grammar/description/
#include "one.h"

class Solution {
public:
  int kthGrammar(int N, int K) {
    if (N == 1) {
      return 0;
    }
    // 奇数索引的节点值与父节点相同
    if (K & 1) {
      return kthGrammar(N - 1, (K + 1) / 2);
    }
    // 偶数节点的值与父节点值相反
    return kthGrammar(N - 1, K / 2) == 1 ? 0 : 1;
  }
};
