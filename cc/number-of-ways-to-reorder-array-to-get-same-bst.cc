// http://leetcode.com/problems/number-of-ways-to-reorder-array-to-get-same-bst/description/
#include "xxx.h"

class Solution {
public:
  int numOfWays(vector<int> &nums) {
    const int n = nums.size();
    dp_ = vector<vector<int>>(n + 1, vector<int>(n + 1, -1));
    mod_ = pow(10, 9) + 7;

    return dfs(nums) - 1;
  }

private:
  long dfs(vector<int> &n) {
    if (n.size() <= 1) {
      return 1;
    }
    vector<int> n1;
    vector<int> n2;
    copy_if(begin(n), end(n), back_inserter(n1),
            [&](int i) { return i < n.front(); });
    copy_if(begin(n), end(n), back_inserter(n2),
            [&](int i) { return i > n.front(); });

    return dfs(n1) * dfs(n2) % mod_ * comb(n1.size(), n2.size()) % mod_;
  }
  int comb(int n, int m) {
    if (n == 0 || m == 0) {
      return 1;
    }
    if (dp_[n][m] != -1) {
      return dp_[n][m];
    }
    dp_[n][m] = (comb(n - 1, m) + comb(n, m - 1)) % mod_;

    return dp_[n][m];
  }

private:
  vector<vector<int>> dp_;
  int mod_;
};
