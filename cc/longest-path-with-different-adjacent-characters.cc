// https://leetcode.com/problems/longest-path-with-different-adjacent-characters/
#include "xxx.hpp"

class Solution {
public:
  int longestPath(vector<int> &parent, string s) {
    int sz = parent.size();
    // onlly one node
    int ret = 1;
    // start from leave, i.e. this value is 0
    vector<int> child_count(sz, 0);
    vector<int> top1(sz, 1);
    vector<int> top2(sz, 1);
    for (int i = 1; i < sz; ++i) {
      ++child_count[parent[i]];
    }
    queue<int> q;
    for (int i = 0; i < sz; ++i) {
      if (child_count[i] == 0) {
        q.push(i);
      }
    }

    while (!q.empty() && q.front() != 0) {
      int cur = q.front();
      int cur_parent = parent[cur];
      q.pop();
      // path max value, from cur to cur's parent
      int cur_len = 1 + (s[cur] != s[cur_parent] ? top1[cur] : 0);
      if (top1[cur_parent] <= cur_len) {
        top2[cur_parent] = top1[cur_parent];
        top1[cur_parent] = cur_len;
      } else {
        top2[cur_parent] = max(top2[cur_parent], cur_len);
      }

      // merge done, we going up again
      if (--child_count[cur_parent] == 0) {
        q.push(cur_parent);
        ret = max(ret, top1[cur_parent] + top2[cur_parent] - 1);
      }
    }

    return ret;
  }
};
