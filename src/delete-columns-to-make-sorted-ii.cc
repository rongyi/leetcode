// http://leetcode.com/problems/delete-columns-to-make-sorted-ii/description/
#include "xxx.h"

class Solution {
public:
  int minDeletionSize(vector<string> &A) {
    const int m = A.size();
    const int n = A[0].size();
    int ret = 0;
    // 只要找到一个有序的，就break掉
    // 否则就把这列干掉

    for (int j = 0; j < n; j++) {
      int i = 1;
      bool has_equal = false;
      for (; i < m; i++) {
        if (A[i].substr(0, j + 1) < A[i - 1].substr(0, j + 1)) {
          ret++;
          break;
        } else if (A[i].substr(0, j) == A[i - 1].substr(0, j)) {
          has_equal = true;
        }
      }
      // 这一列就是有序的，OK了，后面不看了
      if (i == m && !has_equal) {
        return ret;
      }
      if (i < m) {
        for (int k = 0; k < m; k++) {
          A[k][j] = '*';
        }
      }
    }

    return ret;
  }
};

int main() {
  Solution so;
  vector<string> input{"dhjwdxmq", "dzsnbenh"};
  so.minDeletionSize(input);
}
