// http://leetcode.com/problems/delivering-boxes-from-storage-to-ports/description/
#include "xxx.h"

class Solution {
public:
  int boxDelivering(vector<vector<int>> &boxes, int portsCount, int maxBoxes,
                    int maxWeight) {
    // 截止到i个box的船最小趟数我们定义在 dp[i + 1]
    // 然后用sliding window来计算最小的
    // box[i][0] ==> 港口目的地
    // box[i][1] ==> 货重量
    const int n = boxes.size();
    vector<int> dp(n + 1, 0);

    // slidingwindow的左侧
    int i = 0;
    int cur_cost = 1; // 返回货物港口的那趟
    int cur_weight = 0;
    // sliding window的右侧，闭区间
    for (int j = 0; j < n; ++j) {
      // 港口目的地增加了
      if (j == 0 || boxes[j][0] != boxes[j - 1][0]) {
        cur_cost += 1;
      }
      cur_weight += boxes[j][1];

      // 最后一个判断是如果dp[i + 1] == dp[i] 那么到 i 和到 i -
      // 1这里跑的趟数是一样的，那就放一起跑了吧，
      // 因为放在后面的话，可能会多一趟，目的一样还好说，目的不一样就要多跑一趟了
      while (j - i + 1 > maxBoxes || cur_weight > maxWeight ||
             (i < j && dp[i + 1] == dp[i])) {
        cur_weight -= boxes[i][1];

        // 我们只在港口目的地不一样的时候增加了，相应的也去减少
        if (boxes[i][0] != boxes[i + 1][0]) {
          cur_cost -= 1;
        }
        i++;
      }

      // 区间收录的是[i, j]个box， 截止到i-1的统计是dp[i]
      dp[j + 1] = dp[i] + cur_cost;
    }

    return dp[n];
  }
};
