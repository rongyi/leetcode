// http://leetcode.com/problems/partition-array-for-maximum-sum/description/
#include "xxx.hpp"

class Solution {
public:
  // at most K
  int maxSumAfterPartitioning(vector<int> &A, int K) {
    const int n = A.size();

    // dp[i] 表示这里不管多少个K一组，到这里的和
    vector<int> dp(n, 0);
    for (int i = 0; i < n; ++i) {
      int cur_max = 0;
      for (int k = 1; k <= K && i - k + 1 >= 0; ++k) {
        cur_max = max(cur_max, A[i - k + 1]);
        dp[i] = max(dp[i], (i >= k ? dp[i - k] : 0) + cur_max * k);
      }
    }

    return dp[n - 1];
  }
};

int main() {
  Solution so;
  vector<int> input{1, 7, 3, 4};
  auto ret = so.maxSumAfterPartitioning(input, 3);
  cout << ret << endl;
}
