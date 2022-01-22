// http://leetcode.com/problems/closest-room/description/
#include "xxx.hpp"

class Solution {
public:
  vector<int> closestRoom(vector<vector<int>> &rooms,
                          vector<vector<int>> &queries) {
    // 不需要去考虑是否被占的情况，只是让你返回符合条件的就是了。在这里多废时间，真的是
    // number the query
    for (int i = 0; i < queries.size(); ++i) {
      queries[i].push_back(i);
    }
    // query from bigger to small
    sort(queries.begin(), queries.end(),
         [](auto &l, auto &r) { return l[1] > r[1]; });
    vector<int> ret(queries.size(), 0);
    // sort room from bigger to small
    sort(rooms.begin(), rooms.end(),
         [](auto &l, auto &r) { return l[1] > r[1]; });

    set<int> valid;
    int i = 0;
    const int sz = rooms.size();
    for (auto &q : queries) {
      int cur_pref = q[0];
      int cur_min_sz = q[1];
      int cur_idx = q[2];
      int cur_satisfied = -1;
      while (i < sz && rooms[i][1] >= cur_min_sz) {
        // make room id sorted in a binary tree
        valid.insert(rooms[i][0]);
        i++;
      }
      if (valid.size()) {
        int cur_diff = numeric_limits<int>::max();
        auto it = valid.upper_bound(cur_pref);
        if (it != valid.end()) {
          cur_diff = abs(cur_pref - *it);
          cur_satisfied = *it;
        }
        if (it != valid.begin()) {
          --it;
          if (abs(*it - cur_pref) <= cur_diff) {
            // don't need to update this value
            // cur_diff = abs(*it - cur_pref);
            cur_satisfied = *it;
          }
        }
        ret[cur_idx] = cur_satisfied;
      } else {
        ret[cur_idx] = -1;
      }
    }

    return ret;
  }
};
