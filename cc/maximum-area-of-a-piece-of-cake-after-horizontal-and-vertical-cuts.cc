// http://leetcode.com/problems/maximum-area-of-a-piece-of-cake-after-horizontal-and-vertical-cuts/description/
#include "xxx.h"

class Solution {
public:
  int maxArea(int h, int w, vector<int> &horizontalCuts,
              vector<int> &verticalCuts) {
    sort(horizontalCuts.begin(), horizontalCuts.end());
    sort(verticalCuts.begin(), verticalCuts.end());
    int max_ho = max(horizontalCuts[0], h - horizontalCuts.back());
    int max_vo = max(verticalCuts[0], w - verticalCuts.back());

    for (int i = 1; i < horizontalCuts.size(); ++i) {
      max_ho = max(max_ho, horizontalCuts[i] - horizontalCuts[i - 1]);
    }
    for (int j = 1; j < verticalCuts.size(); ++j) {
      max_vo = max(max_vo, verticalCuts[j] - verticalCuts[j - 1]);
    }

    return (long long)max_ho * max_vo % (long long)(pow(10, 9) + 7);
  }
};
