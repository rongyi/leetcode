// http://leetcode.com/problems/nim-game/description/
#include "xxx.hpp"

class Solution {
public:
  bool canWinNim(int n) {
    if (n <= 3) {
      return true;
    }

    vector<int> dp(n + 1, 0);
    dp[0] = false;
    dp[1] = true;
    dp[2] = true;
    dp[3] = true;

    // so for the first
    for (int i = 4; i <= n; i++) {
      dp[i] = (!dp[i - 1]) || (!dp[i - 2]) || (!dp[i - 3]);
    }

    // as you can see, when n == 4 , value is false;
    for (int i = 0; i <= n; i++) {
      cout << dp[i] << " ";
    }
    cout << endl;
    return dp[n];
  }
};

class SolutionTrick {
public:
  // https://leetcode.com/problems/nim-game/discuss/73749/Theorem%3A-all-4s-shall-be-false
  // Proof:
  // the base case: when n = 4, as suggested by the hint from the problem, no
  // matter which number that that first player, the second player would always
  // be able to pick the remaining number. For 1* 4 < n < 2 * 4, (n = 5, 6, 7),
  // the first player can reduce the initial number into 4 accordingly, which
  // will leave the death number 4 to the second player. i.e. The numbers 5, 6,
  // 7 are winning numbers for any player who got it first. Now to the beginning
  // of the next cycle, n = 8, no matter which number that the first player
  // picks, it would always leave the winning numbers (5, 6, 7) to the second
  // player. Therefore, 8 % 4 == 0, again is a death number. Following the
  // second case, for numbers between (2*4 = 8) and (3*4=12), which are 9, 10,
  // 11, are winning numbers for the first player again, because the first
  // player can always reduce the number into the death number 8.
  bool canWinNim(int n) { return n % 4 != 0; }
};

int main(int argc, char *argv[]) {
  Solution so;
  so.canWinNim(100);
  return 0;
}
