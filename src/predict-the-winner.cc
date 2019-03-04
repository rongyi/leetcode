// http://leetcode.com/problems/predict-the-winner/description/
#include "xxx.h"

class Solution {
public:
  // https://leetcode.com/problems/predict-the-winner/discuss/96829/DP-O(n2)-%2B-MIT-OCW-solution-explanation
  bool PredictTheWinner(vector<int> &nums) {
    // 先算奇数位置和以及偶数位置和，然后看哪个和大，
    // 首尾分别占奇偶位置，对应去就是了
    if (nums.size() % 2 == 0) {
      return true;
    }
    const int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    int my_best = recur(nums, dp, 0, n - 1);

    return 2 * my_best >= accumulate(nums.begin(), nums.end(), 0);
  }
  int recur(vector<int> &v, vector<vector<int>> &dp, int i, int j) {
    if (i > j) {
      return 0;
    }
    if (dp[i][j] == -1) {
      return dp[i][j];
    }
    // (i, j) 此时轮到自己走，分两种情况
    // 1. 我取 v[i] , 那么剩下 (i + 1, j) 以及轮到对手走，对手可以取 v[i + 1],
    // 也可以取 v[j]，那么取哪个呢，肯定是要剩下最小的那个
    // recur(v, dp, i + 1, j - 1) ==> 对手此时取 v[j]
    // recur(v, dp, i + 2, j) ==> 对手此时取 v[i + 1]

    // 2. I pick v[j] the save as above, opponent have (i, j - 1)
    // recur(v, dp, i, j - 2) ==> opponent pick v[j - 1]
    // recur(v, dp, i + 1, j - 1) ==> opponent pick v[i]
    // 对手和你一样强，所以自己获得的肯定是最小的
    int a = v[i] + min(recur(v, dp, i + 1, j - 1), recur(v, dp, i + 2, j));
    int b = v[j] + min(recur(v, dp, i, j - 2), recur(v, dp, i + 1, j - 1));

    dp[i][j] = max(a, b);

    return dp[i][j];
  }
};
