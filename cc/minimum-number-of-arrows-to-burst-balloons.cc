// http://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/description/
#include "xxx.hpp"

class Solution {
public:
  // 尽可能的一箭多雕
  int findMinArrowShots(vector<vector<int>> &points) {
    sort(points.begin(), points.end(),
         [](auto &l, auto &r) -> bool { return l[1] < r[1]; });
    int ret = 0;
    int arrow = 0;
    int i = 0;
    const int n = points.size();
    while (i < n) {
      ret++;
      arrow = points[i][1];
      // this arrow can shot these balloon as well
      while (i < n && points[i][0] <= arrow) {
        i++;
      }
    }

    return ret;
  }
};

int main() {
  Solution so;
  vector<vector<int>> input{{10, 16}, {2, 8}, {1, 6}, {7, 12}};
  so.findMinArrowShots(input);
}
