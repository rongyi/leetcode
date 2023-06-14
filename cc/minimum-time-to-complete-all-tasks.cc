// https://leetcode.com/problems/minimum-time-to-complete-all-tasks/
#include "xxx.hpp"

class Solution {
public:
  // take time as interval, not point
  // so [5, 5] in example is valid, it running 1 time slice
  int findMinimumTime(vector<vector<int>> &tasks) {
    // mark the time of index i is running or not
    vector<int> mark(2001, 0);
    sort(tasks.begin(), tasks.end(),
         [](auto &t1, auto &t2) { return t1[1] < t2[1]; });

    for (auto &t : tasks) {
      int start = t[0];
      int end = t[1];
      int duration = t[2];
      duration -= count(mark.begin() + start, mark.begin() + end + 1, true);
      // start from last to mark duration when duration need to fill more
      for (int i = end; duration > 0; i--) {
        // when current slot is not on, we turn it one, and update duration
        duration -= !mark[i];
        // ensure
        mark[i] = true;
      }
    }

    return count(mark.begin(), mark.end(), true);
  }
};

int main() {
  Solution so;
  vector<vector<int>> input{{1, 3, 2}, {2, 5, 3}, {5, 6, 2}};
  so.findMinimumTime(input);
}
