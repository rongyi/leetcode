// http://leetcode.com/problems/find-center-of-star-graph/description/
#include "xxx.hpp"

class Solution {
public:
  int findCenter(vector<vector<int>> &edges) {
    // 中心节点的度数是 n - 1
    int max_degree = 0;
    int max_node = 0;
    map<int, int> count;
    for (auto &e : edges) {
      count[e[1]]++;
      count[e[0]]++;
      if (count[e[0]] > max_degree) {
        max_degree = count[e[0]];
        max_node = e[0];
      }
      if (count[e[1]] > max_degree) {
        max_degree = count[e[1]];
        max_node = e[1];
      }
    }

    return max_node;
  }
};
