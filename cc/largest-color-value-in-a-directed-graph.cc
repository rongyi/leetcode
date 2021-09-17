// http://leetcode.com/problems/largest-color-value-in-a-directed-graph/description/
#include "xxx.h"

class Solution {
public:
  int largestPathValue(string colors, vector<vector<int>> &edges) {
    // color vector
    using cv = array<int, 26>;
    // sz indicate the node number
    const int sz = colors.size();
    // edges by node
    map<int, vector<int>> ne;
    vector<int> in_degree(sz, 0);
    // all_color[i][j] ==>node i of color j count
    vector<cv> all_color(sz, cv{});
    for (auto &e : edges) {
      ne[e[0]].push_back(e[1]);
      in_degree[e[1]]++;
    }

    queue<int> q;

    // start from the in degree 0
    for (int i = 0; i < sz; ++i) {
      if (in_degree[i] == 0) {
        q.push(i);
        all_color[i][colors[i] - 'a'] = 1;
      }
    }

    int seen = 0;
    int ret = 0;
    while (!q.empty()) {
      auto cur_node = q.front();
      q.pop();
      int cur_max_color =
          *max_element(all_color[cur_node].begin(), all_color[cur_node].end());
      ret = max(ret, cur_max_color);
      seen++;

      // update method
      for (auto &nxt : ne[cur_node]) {
        // update color
        for (int i = 0; i < 26; ++i) {
          all_color[nxt][i] = max(
              all_color[nxt][i],
              // 看这里的delegation，从上一个节点过来的时候的和当前节点颜色所能组成的最大值
              all_color[cur_node][i] + (i == (colors[nxt] - 'a')));
        }
        if (--in_degree[nxt] == 0) {
          q.push(nxt);
        }
      }
    }

    if (seen < sz) {
      return -1;
    }
    return ret;
  }
};
