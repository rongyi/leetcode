// http://leetcode.com/problems/spiral-matrix-ii/description/
#include "xxx.h"

class Solution {
public:
  vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> ret(n, vector<int>(n, 0));


    auto beginx = 0;
    auto endx = n - 1;

    auto beginy = 0;
    auto endy = n - 1;
    auto index = 1;

    //    ----------> ++beginx
    // ++beginy
    //   ^                |
    //   |                |
    //   |                |
    //   |                |
    //   |                v
    // --endx<--------- --endy

    // 这里有一个规律，无论横着，竖着，反着，正着都循环里边界都很固定，
    // 个人觉得难点在更新边界，说明在更新部分
    while (true) {
      // left --> right
      for (int j = beginy; j <= endy; ++j) {
        ret[beginx][j] = index++;
      }
      // 第一行走完了，后续的行操作都从下一行开始
      if (++beginx > endx) {
        break;
      }
      // top --> down
      for (int i = beginx; i <= endx; ++i) {
        ret[i][endy] = index++;
      }
      // 最后一列走完，后续的列操作都到前面一列终止
      if (--endy < beginy) {
        break;
      }
      // right --> left
      for (int j = endy; j >= beginy; --j) {
        ret[endx][j] = index++;
      }
      // 最后一行走完，行操作都到前面一行
      if (--endx < beginx) {
        break;
      }
      // down --> top
      for (int i = endx; i >= beginx; --i) {
        ret[i][beginy] = index++;
      }
      // 第一列走完，后续列下一列开始
      if (++beginy > endy) {
        break;
      }
    }
    return ret;
  }
};
