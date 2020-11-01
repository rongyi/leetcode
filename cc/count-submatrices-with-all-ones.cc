// http://leetcode.com/problems/count-submatrices-with-all-ones/description/
#include "xxx.h"

class Solution {
public:
  int numSubmat(vector<vector<int>> &mat) {
    const int m = mat.size();
    const int n = mat[0].size();
    int ret = 0;

    for (int i = 0; i < m; ++i) {
      // 压缩到一维上面来统计
      // 从row i ==> row j
      // 为1的都压缩到一行上面，然后统计这个一行上面的数量
      vector<int> compress(n, 1);
      for (int j = i; j < m; ++j) {
        for (int k = 0; k < n; ++k) {
          compress[k] &= mat[j][k];
        }
        ret += count(compress);
      }
    }
    return ret;
  }

private:
  // 一维数组的统计方法
  int count(vector<int> &lst) {
    int ret = 0;
    int cur_len = 0;

    for (int i = 0; i < lst.size(); ++i) {
      cur_len = lst[i] == 0 ? 0 : cur_len + 1;
      ret += cur_len;
    }

    return ret;
  }
};

int main() {
  Solution so;
  vector<vector<int>> input{{0, 1, 1, 1}, {1, 0, 1, 1}, {1, 1, 1, 0}};
  so.numSubmat(input);
}
