// http://leetcode.com/problems/group-the-people-given-the-group-size-they-belong-to/description/
#include "xxx.h"

class Solution {
public:
  // 1. group same size together and slice each group by group size
  vector<vector<int>> groupThePeople(vector<int> &groupSizes) {
    unordered_map<int, vector<int>> groups;
    for (int i = 0; i < groupSizes.size(); i++) {
      groups[groupSizes[i]].push_back(i);
    }
    vector<vector<int>> ret;
    for (auto &kv : groups) {
      const int len = kv.first;
      // kv.second.size() % len == 0
      const int sections = kv.second.size() / len;
      for (int i = 0; i < sections; i++) {
        vector<int> cur;
        for (int j = 0; j < len; j++) {
          cur.push_back(kv.second[i * len + j]);
        }
        ret.push_back(cur);
      }
    }

    return ret;
  }
};
