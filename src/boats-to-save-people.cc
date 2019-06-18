// http://leetcode.com/problems/boats-to-save-people/description/
#include "xxx.h"

class Solution {
public:
  int numRescueBoats(vector<int> &people, int limit) {
    const int n = people.size();
    sort(people.begin(), people.end());
    int i = 0;
    int j = 0;
    int ret = 0;
    for (i = 0, j = n - 1; i <= j; --j, ++ret) {
      // 体重小的跟大的可以一起，那么久一起走吧
      // 如果不行，小的不动，大的单独上一条船走咯
      if (people[i] + people[j] <= limit) {
        ++i;
      }
    }
    return ret;
  }
};
