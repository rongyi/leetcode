// http://leetcode.com/problems/course-schedule-ii/description/
#include "xxx.h"

class Solution {
public:
  vector<int> findOrder(int numCourses, vector<pair<int, int>> &prerequisites) {
    vector<int> ret;
    vector<vector<int>> graph(numCourses, vector<int>(0));
    vector<int> in(numCourses, 0);
    for (auto &e : prerequisites) {
      graph[e.second].push_back(e.first);
      ++in[e.first];
    }
    // 具体细节参见 course schedule i
    std::queue<int> q;
    for (int i = 0; i < numCourses; ++i) {
      if (in[i] == 0)
        q.push(i);
    }

    while (!q.empty()) {
      int n = q.front();
      ret.push_back(n);
      q.pop();
      for (auto &e : graph[n]) {
        --in[e];
        if (in[e] == 0)
          q.push(e);
      }
    }
    if (ret.size() != numCourses)
      ret.clear();

    return ret;
  }
};
