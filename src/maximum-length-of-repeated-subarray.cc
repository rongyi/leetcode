// http://leetcode.com/problems/maximum-length-of-repeated-subarray/description/
#include "xxx.h"

class Solution {
public:
  // dp[i][j]: max length of common subarray start at a[i] and b[j]
  // dp[i][j] = a[i] == b[j] ? 1 + dp[i + 1][j + 1] : 0
  int findLength(vector<int> &a, vector<int> &b) {
    const int m = a.size();
    const int n = b.size();
    if (m == 0 || n == 0) {
      return 0;
    }
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    int ret = 0;
    for (int i = m - 1; i >= 0; i--) {
      for (int j = n - 1; j >= 0; j--) {
        // 为什么倒着来？
        // 因为递推公式用到后面的值，所以得先算
        ret = max(ret, dp[i][j] = a[i] == b[j] ? 1 + dp[i + 1][j + 1] : 0);
      }
    }

    return ret;
  }
};
int main() {
  Solution so;
  vector<int> input1{1, 2, 3, 2, 1};
  vector<int> input2{3, 2, 1, 4, 7};
  auto ret = so.findLength(input1, input2);
  cout << ret << endl;
}
