// http://leetcode.com/problems/finding-the-users-active-minutes/description/
#include "xxx.hpp"

class Solution {
public:
  vector<int> findingUsersActiveMinutes(vector<vector<int>> &logs, int k) {
    unordered_map<int, unordered_set<int>> count;
    for (auto &l : logs) {
      // user l[0] active at time l[1]
      count[l[0]].insert(l[1]);
    }
    vector<int> ret(k, 0);

    // 题目意思很难受，就是统计UMA的值对应的次数
    for (auto kv : count) {
      ret[kv.second.size() - 1]++;
    }

    return ret;
  }
};
