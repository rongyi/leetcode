// http://leetcode.com/problems/number-of-students-doing-homework-at-a-given-time/description/
#include "xxx.h"

class Solution {
public:
  int busyStudent(vector<int> &startTime, vector<int> &endTime, int queryTime) {
    vector<pair<int, int>> itvs;
    for (int i = 0; i < startTime.size(); ++i) {
      itvs.push_back({startTime[i], endTime[i]});
    }
    // 都没必要去sort了
    // sort(begin(itvs), end(itvs));
    int ret = 0;

    for (auto &p : itvs) {
      if (p.first <= queryTime && p.second >= queryTime) {
        ret++;
      }
    }

    return ret;
  }
};
