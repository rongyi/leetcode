// http://leetcode.com/problems/delete-columns-to-make-sorted-ii/description/
#include "xxx.hpp"

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
        string prev = A[i - 1].substr(0, j + 1);
        string cur = A[i].substr(0, j + 1);
        if (prev > cur) {
          ret++;
          break;
        } else if (prev == cur) {
          has_equal = true;
        }
      }
      // 这一列就是有序的，OK了，后面不看了
      if (i == m && !has_equal) {
        return ret;
      }
      // 如果 i == m那么这一列在排序的时候不影响后续结果了
      // 否则就影响后续string检测结果，所以这里为了消除这一列
      // 的影响，将这一列全变成一样的，这样就不影响后续substr排序结果了
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
  vector<string> input{"xga", "xfb", "yfa"};
  so.minDeletionSize(input);
}
