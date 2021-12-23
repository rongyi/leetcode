// https://leetcode.com/problems/detect-squares/
#include "xxx.h"

class DetectSquares {
public:
  DetectSquares() { matrix_ = vector<vector<int>>(1001, vector<int>(1001, 0)); }

  void add(vector<int> point) { matrix_[point[0]][point[1]] += 1; }

  // just count the matrix
  int count(vector<int> point) {
    int x = point[0];
    int y = point[1];

    int ret = 0;
    for (int i = 0; i < 1001; ++i) {
      if (i != x && matrix_[i][y]) {
        // square size
        int sz = abs(i - x);
        // the right one
        if (y + sz < 1001) {
          ret += matrix_[i][y + sz] * matrix_[x][y + sz] * matrix_[i][y];
        }
        // the left one
        if (y >= sz) {
          ret += matrix_[i][y - sz] * matrix_[x][y - sz] * matrix_[i][y];
        }
      }
    }

    // at last decrease this count
    return ret;
  }

private:
  vector<vector<int>> matrix_;
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */

int main() {
  DetectSquares detectSquares = DetectSquares();
  detectSquares.add({3, 10});
  detectSquares.add({11, 2});
  detectSquares.add({3, 2});
  detectSquares.count({11, 10});
}
