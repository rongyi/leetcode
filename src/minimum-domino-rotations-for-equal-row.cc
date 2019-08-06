// http://leetcode.com/problems/minimum-domino-rotations-for-equal-row/description/
#include "xxx.h"

class Solution {
public:
  int minDominoRotations(vector<int> &A, vector<int> &B) {
    const int n = A.size();
    // 3 ...
    // 5 ...
    // 如果最后旋转的目的数字不是3或者5,那么第一个数字就完不成，就直接返回-1了
    for (int i = 0, flipa = 0, flipb = 0;
         i < n && (A[i] == A[0] || B[i] == A[0]); i++) {
      if (A[i] != A[0]) {
        ++flipa;
      }
      if (B[i] != A[0]) {
        ++flipb;
      }
      if (i == n - 1) {
        return min(flipa, flipb);
      }
    }

    for (int i = 0, flipa = 0, flipb = 0;
         i < n && (A[i] == B[0] || B[i] == B[0]); i++) {
      if (A[i] != B[0]) {
        ++flipa;
      }
      if (B[i] != B[0]) {
        ++flipb;
      }
      if (i == n - 1) {
        return min(flipa, flipb);
      }
    }

    return -1;
  }
};

int main() {
  Solution so;
  vector<int> a{2, 1, 2, 4, 2, 2};
  vector<int> b{5, 2, 6, 2, 3, 2};
  auto ret = so.minDominoRotations(a, b);
  cout << ret << endl;
}
