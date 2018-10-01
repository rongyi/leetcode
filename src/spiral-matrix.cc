// http://leetcode.com/problems/spiral-matrix/description/
#include "one.h"

class Solution {
public:
  vector<int> spiralOrder(vector<vector<int>> &matrix) {
    vector<int> ret;

    const int m = matrix.size();
    if (m == 0) {
      return ret;
    }
    const int n = matrix[0].size();

    int beginx = 0;
    int endx = n - 1;

    int beginy = 0;
    int endy = m - 1;

    /**
     ----------> 更新beginy
update benginx       |
    ^                |
    |                |
    |                |
    |                |
    |                v
 更新endy<----------更新endx
    */
    while (true) {
      // left --> right
      for (int j = beginx; j <= endx; ++j) {
        ret.push_back(matrix[beginy][j]);
      }
      // 切掉这一行，beginy在下一行
      if (++beginy > endy) {
        break;
      }
      // top --> down
      for (int i = beginy; i <= endy; ++i) {
        ret.push_back(matrix[i][endx]);
      }
      // 切掉最后这一列，endx缩小
      if (beginx > --endx) {
        break;
      }
      // right --> left
      for (int j = endx; j >= beginx; --j) {
        ret.push_back(matrix[endy][j]);
      }
      // 切掉这一行，endy缩小
      if (beginy > --endy) {
        break;
      }
      // down --> top
      for (int i = endy; i >= beginy; --i) {
        ret.push_back(matrix[i][beginx]);
      }
      // 切掉这一列，beginx增加
      if (++beginx > endx) {
        break;
      }
    }

    return ret;
  }
};

int main() {
  Solution so;
  // vector<vector<int>> input{{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
  // vector<vector<int>> input{{6, 9, 7}};
  vector<vector<int>> input{{1, 2, 3, 4, 5, 6, 7, 8, 9, 10},
                            {11, 12, 13, 14, 15, 16, 17, 18, 19, 20}};
  auto ret = so.spiralOrder(input);
  for (auto i : ret) {
    cout << i << " ";
  }
  cout << endl;
}
