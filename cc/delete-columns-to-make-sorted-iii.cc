// http://leetcode.com/problems/delete-columns-to-make-sorted-iii/description/
#include "xxx.hpp"

class Solution {
public:
  int minDeletionSize(vector<string> &A) {
    const int m = A.size();
    const int n = A[0].size();
    // 最多删仅剩一列，就OK
    int ret = n - 1;
    // dp[i] means the maximum increasing sub sequence ends with i-th element.
    // For all j < i, if A[][j] < A[][i], then dp[j] = max(dp[j], dp[i] + 1)
    vector<int> dp(n, 1);
    // 结尾在j这一列的最长的maximum increasing sub sequence.
    for (int j = 0; j < n; j++) {
      // 从这个位置来跳的意思
      for (int i = 0; i < j; ++i) {
        int k = 0;
        // 有任何一个违反自增的规律，这个节点就不能跳，计算就忽略
        for (; k < m; k++) {
          if (A[k][i] > A[k][j]) {
            break;
          }
        }
        // 说明都是自增了，所以从i这里的subsequence再加一个字符A[i][j]，
        // 然后我们取最大值
        if (k == m && dp[i] + 1 > dp[j]) {
          dp[j] = dp[i] + 1;
        }
      }

      ret = min(ret, n - dp[j]);
    }
    return ret;
  }
};

int main() {
  Solution so;
  vector<string> input{"abcd", "bacd"};
  so.minDeletionSize(input);
}
