// http://leetcode.com/problems/find-kth-largest-xor-coordinate-value/description/
#include "xxx.h"

class Solution {
public:
  int kthLargestValue(vector<vector<int>> &matrix, int k) {
    const int m = matrix.size();
    const int n = matrix[0].size();
    vector<vector<int>> dp(m, vector<int>(n, 0));
    // 小顶堆
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        auto left = j > 0 ? dp[i][j - 1] : 0;
        auto top = i > 0 ? dp[i - 1][j] : 0;
        auto top_left = i > 0 && j > 0 ? dp[i - 1][j - 1] : 0;
        dp[i][j] = left ^ top ^ matrix[i][j] ^ top_left;
        pq.push(dp[i][j]);
        if (pq.size() > k) {
          pq.pop();
        }
      }
    }

    return pq.top();
  }
};

int main() {
  Solution so;
  vector<vector<int>> input{{5, 2}, {1, 6}};
  so.kthLargestValue(input, 1);
}
