// http://leetcode.com/problems/coin-change/description/
#include "simpleone.h"

class Solution {
public:
  int coinChange(vector<int> &coins, int amount) {
    // 最多就1块的分割嘛，所以最大值设成一个不可能的值
    // 自己写的卡在这里
    vector<int> dp(amount + 1, amount + 1);
    dp[0] = 0;

    for (int i = 1; i <= amount; i++) {
      for (auto c : coins) {
        if (i - c >= 0) {
          dp[i] = min(dp[i], dp[i - c] + 1);
        }
      }
    }
    return dp[amount] > amount ? -1 : dp[amount];
  }
};

int main() {
  Solution so;
  vector<int> input{2};
  auto ret = so.coinChange(input, 3);
  cout << ret << endl;
}
