// http://leetcode.com/problems/maximum-height-by-stacking-cuboids/description/
#include "xxx.hpp"

class Solution {
public:
  int maxHeight(vector<vector<int>> &boxes) {
    const int n = boxes.size();
    for (auto &box : boxes) {
      sort(box.begin(), box.end());
    }

    sort(boxes.begin(), boxes.end());

    vector<vector<int>> dp(n, vector<int>(n + 1, 0));

    return dfs(boxes, n - 1, n, dp);
  }

private:
  int dfs(vector<vector<int>> &boxes, int cur_box, int pre_box,
          vector<vector<int>> &dp) {
    if (cur_box < 0) {
      return 0;
    }
    if (dp[cur_box][pre_box] != 0) {
      return dp[cur_box][pre_box];
    }
    // 可取不取当前这个box
    // 1. 不取
    int ret = dfs(boxes, cur_box - 1, pre_box, dp);

    // 还没有垒，或者当前的符合要求，可以放上去
    if ((pre_box == boxes.size()) ||
        (boxes[cur_box][1] <= boxes[pre_box][1]) &&
            (boxes[cur_box][2] <= boxes[pre_box][2])) {
      ret = max(ret, boxes[cur_box][2] + dfs(boxes, cur_box - 1, cur_box, dp));
    }
    dp[cur_box][pre_box] = ret;

    return dp[cur_box][pre_box];
  }
};
