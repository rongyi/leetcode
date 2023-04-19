// http://leetcode.com/problems/the-skyline-problem/description/
#include "xxx.hpp"

class Solution {
public:
  vector<vector<int>> getSkyline(vector<vector<int>> &buildings) {
    // for staring, it is (xpos, -height) (-height to make sure higher
    // score is before the lower height in sort)
    vector<pair<int, int>> critical_lines;
    for (auto &b : buildings) {
      // e.g. {3, 4} {3, 10}
      // the normal sort will be {3, 4}, {3, 10}
      // but what we want is {3, 10} {3, 4}
      // so we make second pos negative
      critical_lines.push_back({b[0], -b[2]});
      critical_lines.push_back({b[1], b[2]});
    }
    sort(critical_lines.begin(), critical_lines.end());
    // make sure the last line get height 0, when leaving
    multiset<int> heights{0};
    // point pos
    vector<vector<int>> ret;
    int prev_height = 0;
    for (auto &line : critical_lines) {
      if (line.second < 0) {
        heights.insert(-line.second);
      } else {
        // this line is leaving
        heights.erase(heights.find(line.second));
      }
      // choose the highest building, all others are shadowed
      int cur_height = *heights.rbegin();
      if (cur_height != prev_height) {
        ret.push_back({line.first, cur_height});
        prev_height = cur_height;
      }
    }

    return ret;
  }
};
