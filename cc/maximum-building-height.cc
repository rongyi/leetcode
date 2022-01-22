// http://leetcode.com/problems/maximum-building-height/description/
#include "xxx.hpp"

class Solution {
public:
  int maxBuilding(int n, vector<vector<int>> &restrictions) {
    restrictions.push_back({1, 0});
    restrictions.push_back({n, n - 1});
    sort(restrictions.begin(), restrictions.end());
    check(restrictions);

    reverse(restrictions.begin(), restrictions.end());
    return check(restrictions);
  }

private:
  int check(vector<vector<int>> &r) {
    int ret = 0;
    for (int i = 0; i < r.size() - 1; ++i) {
      // h1 --> h2这个区间的最高峰
      auto h1 = r[i][1];
      auto h2 = r[i + 1][1];
      // 预期逐步增加1的高度
      auto h = h1 + abs(r[i + 1][0] - r[i][0]);
      // 这一步没想出来，是斜率为1和-1的两条直线的交的高度
      // 如果高了就要往下退，这里不是一步一步退的，数学上的退
      // https://leetcode.com/problems/maximum-building-height/discuss/1175269/C%2B%2B-with-picture-2-passes
      if (h > h2) {
        h = h2 + (h - h2) / 2;
      }
      ret = max(ret, h);
      r[i + 1][1] = min(h, h2);
    }

    return ret;
  }
};
