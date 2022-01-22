// http://leetcode.com/problems/number-of-music-playlists/description/
#include "xxx.hpp"

class Solution {
public:
  // 在一首歌被重放之前至少有K首其他歌被放过
  // dp[N][L] 表示N首歌被放L此并且符合K要求的歌全部由多少种？
  // 边缘case
  // dp[N][N] ==> N首歌放N次，就是个全排列咯： N!
  // dp[0][L] ==> 没歌怎么放？ 0
  // 递推公式：
  // dp[N][L] ==> dp[N - 1][L - 1] * N + dp[N][L - 1] * max(0, N - K)
  // 1. n - 1首歌放L - 1次，最后那首歌没约束直接放，这首歌可以是N首歌中的任意一首，所以有N中可能
  // 2. N首歌放了L - 1次，那最后一首势必是重复的，那就要保证前面 N - K首歌不能用了，之后用N - K之前的歌了
  int numMusicPlaylists(int N, int L, int K) {
    const int mod = pow(10, 9) + 7;

    vector<vector<long long>> dp(1 + N, vector<long long>(1 + L, 0LL));
    dp[1][1] = 1;
    for (int i = 2; i <= N; i++) {
      dp[i][i] = (dp[i - 1][i - 1] * i) % mod;
    }

    for (int n = 1; n <= N; n++) {
      for (int l = n + 1; l <= L; ++l) {
        dp[n][l] = ((dp[n][l - 1] * ((n - K) > 0 ? (n - K) : 0)) % mod +
                    (dp[n - 1][l - 1] * n) % mod) % mod;
      }
    }

    return dp[N][L];
  }
};
