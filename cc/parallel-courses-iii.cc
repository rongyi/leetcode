// https://leetcode.com/problems/parallel-courses-iii/
#include "xxx.h"

class Solution {
public:
  int minimumTime(int n, vector<vector<int>> &relations,
                  vector<int> &course_time) {
    vector<vector<int>> graph(n);
    // distance for each node(pick max)
    vector<int> total_time(n);
    vector<int> indegree(n);
    for (auto &r : relations) {
      // one way, so no reverse pushback
      graph[r[0] - 1].push_back(r[1] - 1);
      ++indegree[r[1] - 1];
    }
    queue<int> q;
    // pick ingress is 0
    for (int i = 0; i < n; ++i) {
      if (indegree[i] == 0) {
        q.push(i);
        // no prev contain, their time is just the learning time
        total_time[i] = course_time[i];
      }
    }
    while (!q.empty()) {
      auto cur_course = q.front();
      q.pop();
      for (auto &next_course : graph[cur_course]) {
        total_time[next_course] =
            max(total_time[next_course],
                total_time[cur_course] + course_time[next_course]);
        --indegree[next_course];
        // only when no prerequisite, can we push them to visit list
        if (indegree[next_course] == 0) {
          q.push(next_course);
        }
      }
    }

    return *max_element(begin(total_time), end(total_time));
  }
};
