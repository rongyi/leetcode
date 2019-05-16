// http://leetcode.com/problems/open-the-lock/description/
#include "xxx.h"

class Solution {
public:
  // Every node has 8 edges. The nodes in dead ends cannot be visited. Find the
  // shortest path from the initial node to the target.
  int openLock(vector<string> &deadends, string target) {
    string init{"0000"};
    unordered_set<string> visited;
    unordered_set<string> dds(deadends.begin(), deadends.end());

    queue<string> q;
    if (dds.find(init) != dds.end()) {
      return -1;
    }
    visited.insert(init);
    q.push(init);

    int ret = 0;
    while (!q.empty()) {
      int len = q.size();
      for (int i = 0; i < len; i++) {
        string t = q.front();
        q.pop();
        vector<string> neis = neighbors(t);
        for (auto s : neis) {
          if (s == target) {
            return ++ret;
          }
          if (visited.find(s) != visited.end()) {
            continue;
          }
          // 没找着，这条路可以往下走
          if (dds.find(s) == dds.end()) {
            q.push(s);
            visited.insert(s);
          }
        }
      }
      ++ret;
    }

    return -1;
  }

private:
  vector<string> neighbors(string &cur) {
    vector<string> ret;
    for (int i = 0; i < cur.size(); i++) {
      string tmp = cur;
      tmp[i] = (cur[i] - '0' + 1) % 10 + '0';
      ret.push_back(tmp);
      tmp[i] = (cur[i] - '0' - 1 + 10) % 10 + '0';
      ret.push_back(tmp);
    }
    return ret;
  }
};
