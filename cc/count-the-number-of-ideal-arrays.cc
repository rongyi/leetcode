// https://leetcode.com/problems/count-the-number-of-ideal-arrays/
#include "xxx.hpp"

// https://leetcode.com/problems/count-the-number-of-ideal-arrays/discuss/2262093/Javapassed-Understandable-Solution-will-Illustration(Solving-Strictly-Increasing-Case-First!)
// easy to understand
class Solution {
public:
  int idealArrays(int n, int maxValue) {
    vector<vector<int>> dp(15, vector<int>(maxValue + 1, 0));
    comb_ = vector<vector<int>>(n, vector<int>(15, -1));

    map<int, vector<int>> divisors;
    for (int i = 1; i <= maxValue; ++i) {
      int j = i * 2;
      while (j <= maxValue) {
        divisors[j].push_back(i);
        j += i;
      }
    }
    for (int i = 1; i <= maxValue; ++i) {
      dp[1][i] = 1;
    }
    for (int i = 2; i <= min(n, 14); ++i) {
      for (int j = 1; j <= maxValue; ++j) {
        for (auto k : divisors[j]) {
          dp[i][j] += dp[i - 1][k];
          dp[i][j] %= mod_;
        }
      }
    }
    for (int i = 1; i <= min(n, 14); ++i) {
      for (int j = 1; j <= maxValue; ++j) {
        dp[i][0] += dp[i][j];
        dp[i][0] %= mod_;
      }
    }
    long long ret = 0;
    for (int i = 1; i <= min(n, 14); ++i) {
      ret = (ret + (long long)choosenofk(n - 1, i - 1) * dp[i][0]) % mod_;
    }

    return ret;
  }

private:
  int choosenofk(int n, int k) {
    if (comb_[n][k] != -1) {
      return comb_[n][k];
    }
    if (k == 0) {
      return comb_[n][k] = 1;
    }
    if (k == 1) {
      return comb_[n][k] = n;
    }
    if (n == k) {
      return comb_[n][k] = 1;
    }
    comb_[n][k] =
        (0ll + choosenofk(n - 1, k - 1) + choosenofk(n - 1, k)) % mod_;

    return comb_[n][k];
  }

private:
  int mod_ = 1e9 + 7;
  vector<vector<int>> comb_;
};

int main(int argc, char *argv[]) {
  Solution so;
  so.idealArrays(2, 16);
  return 0;
}

class Solution2 {
public:
  int idealArrays(int n, int maxValue) {
    comb_ = vector<vector<int>>(n, vector<int>(15, -1));
    // dp[i][j]
    // i: array length
    // j: ending number
    vector<vector<int>> dp(maxValue + 1, vector<int>(15, 0));
    dp[1][1] = 1;
    for (int i = 2; i <= maxValue; ++i) {
      dp[i][1] = 1;
      for (int j = 1; j <= int(sqrt(i)); ++j) {
        int j2 = i / j;
        if (j * j2 == i) {
          for (int k = 1; k < 14; ++k) {
            dp[i][k + 1] += dp[j][k];
          }
          if (j2 != i && j2 != j) {
            for (int k = 1; k < 14; ++k) {
              dp[i][k + 1] += dp[j2][k];
            }
          }
        }
      }
    }

    vector<long long> whole(15, 0);
    for (int i = 1; i < 15; ++i) {
      long long w = 0;
      for (int j = 1; j <= maxValue; ++j) {
        w += dp[j][i];
      }
      whole[i] = w;
    }
    long long ret = 0;

    for (int i = 1; i <= min(n, 14); ++i) {
      ret = (ret + choosenofk(n - 1, i - 1) * whole[i]) % mod_;
    }
    return ret;
  }

private:
  int choosenofk(int n, int k) {
    if (comb_[n][k] != -1) {
      return comb_[n][k];
    }
    if (k == 0) {
      return comb_[n][k] = 1;
    }
    if (k == 1) {
      return comb_[n][k] = n;
    }
    if (n == k) {
      return comb_[n][k] = 1;
    }
    comb_[n][k] =
        (0ll + choosenofk(n - 1, k - 1) + choosenofk(n - 1, k)) % mod_;

    return comb_[n][k];
  }

private:
  int mod_ = 1e9 + 7;
  vector<vector<int>> comb_;
};

