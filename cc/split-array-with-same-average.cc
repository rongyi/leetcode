// http://leetcode.com/problems/split-array-with-same-average/description/
#include "xxx.hpp"

class Solution {
public:
  // https://leetcode.com/problems/split-array-with-same-average/discuss/120667/C%2B%2B-Solution-with-explanation-early-termination-(Updated-for-new-test-case)
  bool splitArraySameAverage(vector<int> &A) {
    const int n = A.size();
    int m = n / 2;
    int total_sum = accumulate(A.begin(), A.end(), 0);
    bool is_possible = false;
    // totalSum/n = Asum/k = Bsum/(n-k), where k = A.size() and 1 <= k <= n/2;
    // Asum = totalSum*k/n, which is an integer. So we have totalSum*k%n == 0;
    // 首先保证集合个数情况, 算数推算出来
    for (int i = 0; i <= m && !is_possible; i++) {
      if (total_sum * i % n == 0) {
        is_possible = true;
      }
    }
    if (!is_possible) {
      return false;
    }
    // vector<vector<unordered_set<int>>> sums(n, vector<unordered_set<int>>(n/2+1));
    // sums[i][j] is all possible combination sum of j numbers from the subarray A[0, i];
    // Goal: sums[n-1][k], for all k in range [1, n/2]
    // Initial condition: sums[i][0] = {0}, 0 <= i <= n-1; sums[0][1] = {all numbers in the array};
    // Deduction: sums[i+1][j] = sums[i][j] "join" (sums[i][j-1] + A[i+1])
    vector<unordered_set<int>> sums(m + 1);
    sums[0].insert(0);
    for (auto num : A) {
      for (int i = m; i >= 1; --i) {
        for (const int t : sums[i - 1]) {
          sums[i].insert(t + num);
        }
      }
    }
    for (int i = 1; i <= m; i++) {
      if (total_sum * i % n == 0 &&
          sums[i].find(total_sum * i / n) != sums[i].end()) {
        return true;
      }
    }
    return false;
  }
};
