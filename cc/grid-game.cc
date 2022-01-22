// https://leetcode.com/problems/grid-game/
#include "xxx.hpp"

class Solution {
public:
  long long gridGame(vector<vector<int>> &grid) {
    using ll = long long;
    ll top = accumulate(grid[0].begin(), grid[0].end(), 0ll);
    ll bottom = 0;
    ll ret = numeric_limits<ll>::max();

    for (int i = 0; i < grid[0].size(); ++i) {
      top -= grid[0][i];
      ret = min(ret, max(top, bottom));
      bottom += grid[1][i];
    }

    return ret;
  }
};
