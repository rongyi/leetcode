// https://leetcode.com/problems/find-the-longest-valid-obstacle-course-at-each-position/
#include "xxx.hpp"

class Solution {
public:
  vector<int> longestObstacleCourseAtEachPosition(vector<int> &obstacles) {
    int sz = obstacles.size();
    vector<int> ret(sz, 0);

    // longest increasing(or equal in this case) subsequence
    vector<int> lis;
    for (int i = 0; i < sz; ++i) {
      int cur = obstacles[i];
      // valid, just push in
      if (lis.empty() || lis.back() <= cur) {
        lis.push_back(cur);
        ret[i] = lis.size();
      } else {
        // replace the value, after modify, lis is still valid
        int idx = upper_bound(lis.begin(), lis.end(), cur) - lis.begin();
        lis[idx] = cur;
        ret[i] = idx + 1;
      }
    }

    return ret;
  }
};
