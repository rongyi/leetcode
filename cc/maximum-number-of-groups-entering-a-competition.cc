// https://leetcode.com/problems/maximum-number-of-groups-entering-a-competition/
#include "xxx.hpp"

class Solution {
public:
  // just sort group
  // just put 1 student to group 1
  // and put 2 student to group 2
  // ...
  int maximumGroups(vector<int> &grades) {
    // sort?
    // sort(grades.begin(), grades.end());
    int sz = grades.size();
    int grp_sz = 1;
    int total_group = 0;

    while (total_group + grp_sz <= sz) {
      total_group += grp_sz;
      grp_sz += 1;
    }

    return grp_sz - 1;
  }
};
