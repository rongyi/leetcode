// http://leetcode.com/problems/building-boxes/description/
#include "xxx.hpp"

class Solution {
public:
  int minimumBoxes(int n) {
    int cur_total_sum = 0;
    int layer_sum = 0;
    int layer = 0; // 就把这当成对角线的长度
    // 可以动态的认为从高处一直往下加，每一层多出来就是对角线的那几块
    // 1
    // 1 + 2
    // 1 + 2 + 3
    // ...
    while (cur_total_sum < n) {
      ++layer;
      layer_sum += layer;
      cur_total_sum += layer_sum;
    }
    // 正好
    if (cur_total_sum == n) {
      return layer_sum;
    }
    // 高了，回滚最后一层
    // 总数减去最下一层
    cur_total_sum -= layer_sum;
    // 最下一层减去对角线的个数
    layer_sum -= layer;
    layer = 0;
    // 从某个方向再逐渐放
    // 1..2 ..3这样的放
    // 地板上多少层就多多少个
    // 看这里的图
    // https://leetcode.com/problems/building-boxes/discuss/1032016/C%2B%2B-Python-3-variables-solution-with-drawing-explanation
    while (cur_total_sum < n) {
      ++layer;
      cur_total_sum += layer;
    }

    return layer_sum + layer;
  }
};
