// http://leetcode.com/problems/set-intersection-size-at-least-two/description/
#include "xxx.hpp"

class Solution {
public:
  int intersectionSizeTwo(vector<vector<int>> &itv) {
    sort(itv.begin(), itv.end(), [](vector<int> &l, vector<int> &r) {
      return l[1] < r[1] || (l[1] == r[1] && l[0] > r[0]);
    });
    const int n = itv.size();
    int ret = 0;
    int p1 = -1;
    int p2 = -1;

    for (int i = 0; i < n; i++) {
      //      |_______|
      //          |___|
      // 按照排序规则，结尾相同的，短的在前
      // 所以出现这种情况 [p1, p2]肯定满足
      if (itv[i][0] <= p1) {
        continue;
      }
      // p1, p2都不满足了
      // 所以至少加上两个元素
      if (itv[i][0] > p2) {
        ret += 2;
        p2 = itv[i][1];
        p1 = p2 - 1;
      } else {
        ret++;
        p1 = p2;
        p2 = itv[i][1];
      }
    }
    return ret;
  }
};
