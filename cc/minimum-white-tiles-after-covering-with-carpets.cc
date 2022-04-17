// https://leetcode.com/problems/minimum-white-tiles-after-covering-with-carpets/
#include "xxx.hpp"

class Solution {
public:
  int minimumWhiteTiles(string floor, int numCarpets, int carpetLen) {
    int sz = floor.size();
    vector<int> cover(sz, 0);
    int total_white = 0;
    int window_sum = 0;
    vector<vector<int>> dp(numCarpets + 1, vector<int>(sz + 1, 0));
    for (int i = 0; i < sz; ++i) {
      total_white += floor[i] - '0';
      window_sum += floor[i] - '0';
      if (i >= carpetLen) {
        window_sum -= floor[i - carpetLen] - '0';
      }
      // a carpet end at [i] can cover num white floor
      cover[i] = window_sum;
    }

    for (int i = 1; i <= numCarpets; ++i) {
      for (int j = 0; j < sz; ++j) {
        dp[i][j + 1] =
            max(dp[i][j],
                (j - carpetLen + 1 >= 0 ? dp[i - 1][j - carpetLen + 1/*don't forget the value is put 1..=sz so with the shift 1*/] : 0) +
                    cover[j]);
      }
    }

    return total_white - dp[numCarpets][sz];
  }
};
