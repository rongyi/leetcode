// http://leetcode.com/problems/evaluate-division/description/
#include "xxx.hpp"

class Solution {
public:
  // 思路：转换成图来解决
  vector<double> calcEquation(vector<pair<string, string>> equations,
                              vector<double> &values,
                              vector<pair<string, string>> queries) {
    auto graph = build_graph(equations, values);
    vector<double> ret(queries.size());
    const int n = queries.size();
    for (int i = 0; i < n; i++) {
      unordered_set<string> visited;
      auto tmp =
          get_weight(queries[i].first, queries[i].second, visited, graph);
      if (tmp) {
        ret[i] = tmp;
      } else {
        ret[i] = -1;
      }
    }
    return ret;
  }

private:
  double get_weight(string up, string down, unordered_set<string> &visited,
                    map<string, map<string, double>> &graph) {
    if (graph.find(up) == graph.end()) {
      return 0;
    }
    // 直联
    if (graph[up].find(down) != graph[up].end()) {
      return graph[up][down];
    }

    // 通过分数相乘得到
    for (auto i : graph[up]) {
      if (visited.find(i.first) == visited.end()) {
        visited.insert(i.first);
        double tmp = get_weight(i.first, down, visited, graph);
        if (tmp) {
          return i.second * tmp;
        }
      }
    }

    return 0;
  }

  // a / b = 3.0 ==> a --> b weight is 3
  map<string, map<string, double>>
  build_graph(vector<pair<string, string>> &equations, vector<double> &values) {
    map<string, map<string, double>> ret;
    string k, v;

    const int n = equations.size();
    for (int i = 0; i < n; i++) {
      k = equations[i].first;
      v = equations[i].second;

      ret[k][v] = values[i];
      ret[v][k] = 1 / values[i];
    }

    return ret;
  }
};
