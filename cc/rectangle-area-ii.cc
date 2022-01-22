// http://leetcode.com/problems/rectangle-area-ii/description/
#include "xxx.hpp"

class Solution {
public:
  // 方法： 逐行扫描:
  // https://leetcode.com/problems/rectangle-area-ii/discuss/137914/C%2B%2BPython-Discretization-and-O(NlogN)
  int rectangleArea(vector<vector<int>> &rectangles) {
    const int mod = pow(10, 9) + 7;
    const int n = rectangles.size();
    vector<long> xcoords;
    vector<long> ycoords;
    for (auto &cur_rec : rectangles) {
      xcoords.push_back(cur_rec[0]);
      xcoords.push_back(cur_rec[2]);

      ycoords.push_back(cur_rec[1]);
      ycoords.push_back(cur_rec[3]);
    }

    // sort y and uniq
    sort(ycoords.begin(), ycoords.end());
    ycoords.erase(unique(ycoords.begin(), ycoords.end()), ycoords.end());

    // sort rects by left x coordinate
    sort(
        rectangles.begin(), rectangles.end(),
        [](const vector<int> &l, const vector<int> &r) { return l[0] < r[0]; });

    long long ret = 0;
    for (int i = 1; i < n; i++) {
      long long startx = rectangles[0][0];
      long long endx = startx;
      long long height = ycoords[i] - ycoords[i - 1];
      for (int j = 0; j < n; j++) {
        if (rectangles[j][3] >= ycoords[i] &&
            rectangles[j][1] <= ycoords[i - 1]) {
          // 不相连了，需要计算前面的值以及重新开始新的startx endx
          //  |   |     |   |
          //  |   |     |   |
          //  |   |     | j |
          // -----------------------------
          //      endx
          if (rectangles[j][0] > endx) {
            ret = (ret + height * (endx - startx)) % mod;
            startx = rectangles[j][0];
            endx = rectangles[j][2];
          } else {
            // 相连或相交的情况下直接延长x部分
            if (rectangles[j][0] <= endx && rectangles[j][2] > endx) {
              endx = rectangles[j][2];
            }
          }
        }
      }
      ret = (ret + height * (endx - startx)) % mod;
    }

    return ret;
  }
};
