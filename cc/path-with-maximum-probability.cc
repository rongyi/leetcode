// http://leetcode.com/problems/path-with-maximum-probability/description/
#include "xxx.hpp"

class Solution {
public:
  double maxProbability(int n, vector<vector<int>> &edges,
                        vector<double> &succProb, int start, int end) {

    vector<vector<pair<int, double>>> nodes(n);
    for (int i = 0; i < edges.size(); ++i) {
      nodes[edges[i][0]].push_back({edges[i][1], succProb[i]});
      nodes[edges[i][1]].push_back({edges[i][0], succProb[i]});
    }
    vector<double> probs(n, 0.0);

    // bring the prob in the node
    queue<int> q;
    q.push(start);
    probs[start] = 1.0;

    while (!q.empty()) {
      auto cur = q.front();
      q.pop();
      // neib ==> pair<node, prob>
      // prob from cur ==> node
      for (auto &neib : nodes[cur]) {
        // 选概率更大的
        // 这个节点当前的概率比从cur过来到此节点的概率要小
        // 那么替换线路从cur过来，这条概率最大
        if (probs[neib.first] < probs[cur] * neib.second) {
          probs[neib.first] = probs[cur] * neib.second;
          q.push(neib.first);
        }
      }
    }

    return probs[end];
  }
};

int main() {}
