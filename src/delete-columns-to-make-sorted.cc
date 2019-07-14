// http://leetcode.com/problems/delete-columns-to-make-sorted/description/
#include "xxx.h"

class Solution {
public:
  // 从未看过踩比例如此之大的题目
  int minDeletionSize(vector<string> &A) {
    int ret = 0;
    int m = A.size();
    int n = A[0].size();
    for (int j = 0; j < n; j++) {
      string cur{};
      for (int i = 0; i < m; i++) {
        // cur.push_back(A[i][j]);
        // this way we quit this column asap
        if (i != 0) {
          if (A[i][j] < A[i - 1][j]) {
            ++ret;
            break;
          }
        }
      }
      // if (!isNonDecreasing(cur)) {
      //   ++ret;
      // }
    }

    return ret;
  }
  // lazy
  bool isNonDecreasing(string &s) {
    const int n = s.size();
    for (int i = 1; i < n; i++) {
      if (s[i] < s[i - 1]) {
        return false;
      }
    }

    return true;
  }
};

int main() {
  Solution so;
  vector<string> input{"cba", "daf", "ghi"};
  so.minDeletionSize(input);
}
