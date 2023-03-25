// http://leetcode.com/problems/clone-graph/description/
// #include "xxx.hpp"
#include <map>
#include <vector>
using namespace std;

// Definition for a Node.
class Node {
public:
  int val;
  vector<Node *> neighbors;
  Node() {
    val = 0;
    neighbors = vector<Node *>();
  }
  Node(int _val) {
    val = _val;
    neighbors = vector<Node *>();
  }
  Node(int _val, vector<Node *> _neighbors) {
    val = _val;
    neighbors = _neighbors;
  }
};

class Solution {
public:
  Node *cloneGraph(Node *node) {
    if (!node) {
      return nullptr;
    }
    if (cache_.count(node->val)) {
      return cache_[node->val];
    }
    Node *cp = new Node(node->val);
    cache_[node->val] = cp;

    for (int i = 0; i < node->neighbors.size(); i++) {
      cp->neighbors.push_back(cloneGraph(node->neighbors[i]));
    }

    return cp;
  }

private:
  map<int, Node *> cache_;
};
