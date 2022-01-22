// http://leetcode.com/problems/dungeon-game/description/
#include "xxx.hpp"

class Solution {
public:
  // 首先，我们应该维护一个2维数组D，与地牢数组的大小相同，其中D[i][j]代表可以保证骑士
  // 在进入房间(i,j)之前，探索其余地牢时能够存活下来的最小HP。显然D[0][0]就是我们
  // 随后需要的最终答案。因此，对于这个问题，我们需要从右下角到左上角填充表格。

  // 然后，我们来计算离开房间(i,j)时的最小HP。从这一点出发只有两条路径可选：
  // (i + 1, j)和(i, j + 1)。当然我们会选择拥有更小D值的那个房间，换言之，
  // 骑士完成剩下的旅途所需的较小HP。因此我们有：

  //   min_HP_on_exit = min(D[i+1][j], D[i][j+1])

  // 现在D[i][j]可以通过dungeon[i][j]和min_HP_on_exit，根据下面的情景得出：

  // 如果dungeon[i][j] == 0，那么在这个房间里很安全。 骑士离开这个房间时的HP和
  // 他进入房间时的HP保持一致， 也就是说 D[i][j] = min_HP_on_exit.

  // 如果dungeon[i][j] < 0，那么骑士在进入该房间之前的HP > 离开房间时的HP，
  // min_HP_on_exit才能抵消他在该房间中的HP损失。 最小HP花费就是
  // "-dungeon[i][j]"， 因此我们有公式 D[i][j] = min_HP_on_exit - dungeon[i][j].

  // 如果dungeon[i][j] > 0, 那么骑士在进入房间(i, j) 时的HP只需为
  // min_HP_on_exit -
  // dungeon[i][j]，因为他可以在该房间内获得数值为"dungeon[i][j]"的HP收益。
  // 不过，这种情况下min_HP_on_exit - dungeon[i][j]的数值可能≤0。
  // 此时，我们需要把值置为1以 确保D[i][j]为正整数: D[i][j] = max(min_HP_on_exit
  // - dungeon[i][j], 1)。

  // 注意 dungeon[i][j] > 0 条件下的等式实际上可以覆盖其他两种情况。
  // 因此我们可以把三种情况归 纳为同一个等式： 亦即:

  // D[i][j] = max(min_HP_on_exit - dungeon[i][j], 1)
  // dungeon[i][j]可以为任意值。
  int calculateMinimumHP(vector<vector<int>> &dungeon) {
    const int m = dungeon.size();
    if (m == 0) {
      return 0;
    }
    const int n = dungeon[0].size();
    vector<vector<int>> dp(m, vector<int>(n, 0));
    // 干完恶魔必须还要多一滴血活命
    dp[m - 1][n - 1] =
        dungeon[m - 1][n - 1] > 0 ? 1 : -dungeon[m - 1][n - 1] + 1;

    for (int i = m - 2; i >= 0; i--) {
      dp[i][n - 1] = max(dp[i + 1][n - 1] - dungeon[i][n - 1], 1);
    }

    for (int j = n - 2; j >= 0; --j) {
      dp[m - 1][j] = max(dp[m - 1][j + 1] - dungeon[m - 1][j], 1);
    }

    for (int i = m - 2; i >= 0; i--) {
      for (int j = n - 2; j >= 0; j--) {
        dp[i][j] = max(1, min(dp[i + 1][j], dp[i][j + 1]) - dungeon[i][j]);
      }
    }

    return dp[0][0];
  }
};
