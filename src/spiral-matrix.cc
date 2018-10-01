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

    auto beginx = 0;
    auto endx = m - 1;

    auto beginy = 0;
    auto endy = n - 1;

    while (true) {
      // left --> right
      for (int j = beginy; j <= endy; ++j) {
        ret.push_back(matrix[beginx][j]);
      }
      if (++beginx > endx) {
        break;
      }
      // top --> down
      for (int i = beginx; i <= endx; ++i) {
        ret.push_back(matrix[i][endy]);
      }
      if (--endy < beginy) {
        break;
      }
      // right --> left
      for (int j = endy; j >= beginy; --j) {
        ret.push_back(matrix[endx][j]);
      }
      if (--endx < beginx) {
        break;
      }
      // down --> top
      for (int i = endx; i >= beginx; --i) {
        ret.push_back(matrix[i][beginy]);
      }
      if (++beginy > endy) {
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
