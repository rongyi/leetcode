// http://leetcode.com/problems/determine-color-of-a-chessboard-square/description/
#include "xxx.h"

class Solution {
public:
  bool squareIsWhite(string coordinates) {
    // index从1开始
    int x = coordinates[0] - 'a' + 1;
    int y = coordinates[1] - '0';

    // 奇偶一样的时候为黑色
    bool isxodd = (x & 1);
    bool isyodd = (y & 1);

    return (isxodd ^ isyodd);
  }
};
