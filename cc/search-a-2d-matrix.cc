// http://leetcode.com/problems/search-a-2d-matrix/description/
#include "xxx.hpp"

class Solution {
public:
  // 本质上所有数字放在一行还是有序的，所以还是二叉查找的另一种说法
  bool searchMatrix(vector<vector<int>> &matrix, int target) {

    const int m = matrix.size();
    if (m == 0) {
      return false;
    }
    const int n = matrix[0].size();
    int left = 0;
    int right = m * n;
    while (left < right) {
      auto mid = left + (right - left) / 2;
      // 每一行有n个，那么排在第几行？
      auto row = mid / n;
      auto col = mid % n;
      if (target == matrix[row][col]) {
        return true;
      } else if (target > matrix[row][col]) {
        left = mid + 1;
      } else {
        right = mid;
      }
    }

    return false;
  }
};

int main() {
  Solution so;
  vector<vector<int>> input{{1, 3, 5}};
  auto ret = so.searchMatrix(input, 0);
  cout << ret << endl;
}
