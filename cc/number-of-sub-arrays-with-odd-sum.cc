// http://leetcode.com/problems/number-of-sub-arrays-with-odd-sum/description/
#include "xxx.hpp"

class Solution {
public:
  // clang-format off
  // 分析
  // 已知end with i，算end with i + 1
  // 1. 当前num为偶数，则
  //               奇数subarray的个数不变
  //               偶数的subarray个数是 之前偶数 subarray个数 + 1 ==> 所有的之前subarray连上这个值，以及最后一个数独立出来的subarray
  // 2. 当前num为奇数，则
  //               奇数的subarray的个数为之前的偶数subarry + 1 （+1代表的是这个奇数一个数组成的独立数组)
  //               偶数的subarry个数为之前奇数的subarray个数
  // clang-format on
  int numOfSubarrays(vector<int> &arr) {
    int even = 0;
    int odd = 0;
    int ret = 0;
    for (auto &num : arr) {
      if (num & 1) {
        // old style
        // int cur_odd = even + 1;
        // int cur_even = odd;

        // odd = cur_odd;
        // even = cur_even;

        // some improvement
        swap(odd, even);
        ++odd;
      } else {
        ++even;
      }
      ret = (ret + odd) % (int)(1e9 + 7);
    }

    return ret;
  }
};

int main() {
  Solution so;
  vector<int> input{1, 3, 5};
  so.numOfSubarrays(input);
}
