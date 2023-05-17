// http://leetcode.com/problems/coin-change/description/
#include "xxx.hpp"

class Solution {
public:
  int coinChange(vector<int> &coins, int amount) {
    vector<int> dp(amount + 1, numeric_limits<int>::max());
    // state transition initial state
    // we need 0 coin to get 0 amount
    dp[0] = 0;

    for (int i = 1; i <= amount; i++) {
      for (auto &c : coins) {
        // ok, a valid transition
        if (i - c >= 0 && dp[i - c] != numeric_limits<int>::max()) {
          // transition formula
          dp[i] = min(dp[i], dp[i - c] + 1);
        }
      }
    }

    if (dp[amount] == numeric_limits<int>::max()) {
      return -1;
    }

    return dp[amount];
  }
};

int main() {
  Solution so;
  vector<int> input{2};
  auto ret = so.coinChange(input, 3);
  cout << ret << endl;
}
