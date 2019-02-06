// http://leetcode.com/problems/n-ary-tree-level-order-traversal/description/
#include "xxx.h"

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Node {
public:
  int val;
  vector<Node *> children;

  Node() {}

  Node(int _val, vector<Node *> _children) {
    val = _val;
    children = _children;
  }
};

class Solution {

public:
  vector<vector<int>> levelOrder(Node *root) {
    vector<vector<int>> ret;
    recur(root, ret, 1);
    return ret;
  }
  void recur(Node *root, vector<vector<int>> &ret, int cur_level) {
    if (!root) {
      return;
    }
    if (ret.size() < cur_level) {
      ret.push_back({});
    }

    ret[cur_level - 1].push_back(root->val);

    for (auto child : root->children) {
      recur(child, ret, cur_level + 1);
    }
  }
};
