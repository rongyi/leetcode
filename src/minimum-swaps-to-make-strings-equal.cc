// http://leetcode.com/problems/minimum-swaps-to-make-strings-equal/description/
#include "xxx.h"

class Solution {
public:
  int minimumSwap(string s1, string s2) {
    if (s1.size() != s2.size()) {
      return -1;
    }
    // count x in s1
    //       y in s2
    int xy{};
    // count y in s1
    //       x in s2
    int yx{};
    for (int i = 0; i < s1.size(); ++i) {
      if (s1[i] == s2[i]) {
        continue;
      }
      if (s1[i] == 'x') {
        ++xy;
      } else {
        ++yx;
      }
    }
    // 必须成对出现
    if ((xy + yx) % 2) {
      return -1;
    }
    // 先内部消化掉
    // xx
    // yy 这样的case都只需要一次就好了
    int ret = xy / 2 + yx / 2;
    // 和是偶数，只有 1. 两个偶数
    //            2. 两个奇数
    // 不可以是一个奇数一个偶数
    // 前面和保证是偶数，所以要么就不剩下，要么就各自都剩一个
    // xy
    // yx 这样的组合需要两次swap
    if (xy % 2) {
      ret += 2;
    }
    return ret;
  }
};
