// http://leetcode.com/problems/coin-change/description/
#include "xxx.hpp"

class Solution {
public:
  int coinChange(vector<int> &coins, int amount) {
    // 自己最一开始的思路
    vector<int> dp(amount + 1, numeric_limits<int>::max());
    dp[0] = 0;

    for (int i = 1; i <= amount; i++) {
      for (auto c : coins) {
        // 表示i i - c这块找不开，所以基于这个点往后推得也找不开，所以直接不看了
        if (i - c >= 0 && dp[i - c] != numeric_limits<int>::max()) {
          dp[i] = min(dp[i], dp[i - c] + 1);
        }
      }
    }

    return dp[amount] == numeric_limits<int>::max() ? -1 : dp[amount];
  }
};

int main() {
  Solution so;
  vector<int> input{2};
  auto ret = so.coinChange(input, 3);
  cout << ret << endl;
}
