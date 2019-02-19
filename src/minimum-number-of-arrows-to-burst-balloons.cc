// http://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/description/
#include "xxx.h"

class Solution {
public:
  // 尽可能的一箭多雕
  int findMinArrowShots(vector<pair<int, int>> &points) {
    sort(points.begin(), points.end(),
         [](pair<int, int> a, pair<int, int> b) -> bool {
           return a.second < b.second;
         });
    int ret = 0;
    int arrow = 0;
    int i = 0;
    const int n = points.size();
    while (i < n) {
      ret++;
      arrow = points[i].second;
      // this arrow can shot these balloon as well
      while (i < n && points[i].first <= arrow) {
        i++;
      }
    }

    return ret;
  }
};

int main() {
  Solution so;
  vector<pair<int, int>> input{{10, 16}, {2, 8}, {1, 6}, {7, 12}};
  so.findMinArrowShots(input);
}
