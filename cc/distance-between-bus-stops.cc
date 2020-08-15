// http://leetcode.com/problems/distance-between-bus-stops/description/
#include "xxx.h"

class Solution {
public:
  int distanceBetweenBusStops(vector<int> &distance, int start,
                              int destination) {
    auto circle = accumulate(distance.begin(), distance.end(), 0ll);

    long long part = 0;
    if (start > destination) {
      int tmp = start;
      start = destination;
      destination = tmp;
    }
    for (int i = start; i < destination; ++i) {
      part += distance[i];
    }

    return min(part, circle - part);
  }
};
