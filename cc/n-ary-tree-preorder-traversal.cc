// http://leetcode.com/problems/n-ary-tree-preorder-traversal/description/
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

class Solution {
public:
  vector<int> preorder(Node *root) {
    vector<int> ret;
    recur(root, ret);
    return ret;
  }

private:
  void recur(Node *root, vector<int> &ret) {
    if (!root) {
      return;
    }
    ret.push_back(root->val);
    for (auto p : root->children) {
      recur(p, ret);
    }
  }
};
