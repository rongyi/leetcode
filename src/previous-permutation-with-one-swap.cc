// http://leetcode.com/problems/previous-permutation-with-one-swap/description/
#include "xxx.h"

class Solution {
public:
  // 喷的很惨，没什么意思
  // 题意：给一个数列A，求选两个位置进行交换一次，使得新得到的数列字典序小于A，且是最大的数列。

  // 思路：求小于字典序且最大，那交换的两个位置就需要尽可能的靠后。

  // 由于是求小于字典中的序列，只需要从后到前，找到第一个非递减的序列。
  // 如b[i] > b[i+1] <= b[i+2] <= ... <= b[n]。
  // 如果i不存在，则说明整个数列就是最小的，返回原数列即可。
  // 否则在b[i+1] ~ b[n]里面挑一个小于 b[i]的数字进行交换。
  vector<int> prevPermOpt1(vector<int> &A) {
    int last_pos = A.size() - 1;
    for (; last_pos > 0 && A[last_pos] >= A[last_pos - 1]; --last_pos) {
    }
    if (last_pos == 0) {
      return A;
    }
    last_pos--;

    int swap_pos = A.size() - 1;
    for (; A[swap_pos] >= A[last_pos]; swap_pos--) {
    }
    for (; A[swap_pos] == A[swap_pos - 1]; swap_pos--) {
    }
    swap(A[swap_pos], A[last_pos]);

    return A;
  }
};
