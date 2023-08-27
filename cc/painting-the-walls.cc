// https://leetcode.com/problems/painting-the-walls/
#include "xxx.hpp"

class Solution {
public:
  int paintWalls(vector<int> &cost, vector<int> &time) {
    int sz = time.size();
    return recur(cost, time, 0, sz);
  }

  int recur(vector<int> &cost, vector<int> &time, int cur, int wall_left) {
    if (wall_left <= 0) {
      return 0;
    }
    // make it bigger
    if (cur >= cost.size()) {
      return 1e9;
    }
    if (dp_[cur][wall_left] != 0) {
      return dp_[cur][wall_left];
    }

    // take curent
    int take = cost[cur] +
               recur(cost, time, cur + 1,
                     wall_left - time[cur] -
                         1); // paint[i] cost cost[i]
                             // and use free painter to paint time[cur] walls

    // not take
    int not_take = recur(cost, time, cur + 1, wall_left);
    return dp_[cur][wall_left] = min(take, not_take);
  }

private:
  int dp_[501][501] = {};
};
