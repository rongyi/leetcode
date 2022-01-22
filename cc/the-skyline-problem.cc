// http://leetcode.com/problems/the-skyline-problem/description/
#include "xxx.hpp"

// taken from
// https://leetcode.com/problems/the-skyline-problem/discuss/154793/Short-documented-C%2B%2B-code-(16ms-runtime)
class Solution {
public:
  vector<pair<int, int>> getSkyline(vector<vector<int>> &buildings) {
    // the skyline can only change at the critical points which are either the
    // beginning or the end of a building
    set<int> critical;
    for (auto cur_build : buildings) {
      critical.insert(cur_build[0]);
      critical.insert(cur_build[1]);
    }

    vector<pair<int, int>> skyline;

    int last_height = 0;

    priority_queue<pair<int, int>> active;

    auto cur_build = buildings.begin();

    for (int crit : critical) {
      // any building that started on or before the critical point could be
      // active at the critical point
      while (cur_build != buildings.end() && cur_build->at(0) <= crit) {
        active.push({cur_build->at(2), cur_build->at(1)});
        cur_build++;
      }

      // any building that ends or or before the critical point is not active at
      // the critical point
      while (!active.empty() && active.top().second <= crit)
        active.pop();

      // the height at the critical point is simply the tallest active building
      // note: no active building implies we are at the right edge of a building
      //       hence height is zero.
      int height = 0;
      if (!active.empty())
        height = active.top().first;

      // the skyline only changes when the height at a critical point changes
      if (height != last_height) {
        skyline.push_back({crit, height});
        last_height = height;
      }
    }

    return skyline;
  }
};

int main() {
  Solution so;
  vector<vector<int>> input{{2, 9, 10}, {3, 7, 15}, {5, 12, 12}, {15, 20, 10}, {19, 24, 8}};
  auto ret = so.getSkyline(input);
  for (auto kv : ret) {
    cout << kv.first << " . " << kv.second << endl;
  }
}
