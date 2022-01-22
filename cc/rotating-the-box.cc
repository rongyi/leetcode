// http://leetcode.com/problems/rotating-the-box/description/
#include "xxx.hpp"

class Solution {
public:
  vector<vector<char>> rotateTheBox(vector<vector<char>> &box) {
    int m = box.size();
    int n = box[0].size();

    vector<vector<char>> ret(n, vector<char>(m, '.'));
    // do the roation operation
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        ret[j][i] = box[i][j];
      }
    }
    // for each column, apply gravity
    // comfortable with m n
    swap(m, n);

    for (int j = 0; j < n; ++j) {
      int right_pos = m - 1;
      for (int i = m - 1; i >= 0; --i) {
        // 顺时针旋转90度需要做的调整
        if (j < n / 2) {
          swap(ret[i][j], ret[i][n - j - 1]);
        }
        // obstacle '*'
        if (ret[i][j] == '*') {
          // the next pos is right above this obstacle
          right_pos = i - 1;
        } else if (ret[i][j] == '#') { // stone
          ret[i][j] = '.';
          ret[right_pos][j] = '#';
          right_pos--;
        } // empty, just ignore
      }
    }

    return ret;
  }
};

int main() {
  Solution so;
  vector<vector<char>> input{{'1', '2', '3', '4'}, {'5', '6', '7', '8'}};
  so.rotateTheBox(input);
  // 1 2 3 4
  // 5 6 7 8
  // 5 1
  // 6 2
  // 7 3
  // 8 4
}
