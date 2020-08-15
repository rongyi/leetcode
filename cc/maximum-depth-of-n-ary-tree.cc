// http://leetcode.com/problems/maximum-depth-of-n-ary-tree/description/
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
  int maxDepth(Node *root) {
    if (!root) {
      return 0;
    }
    const int n = root->children.size();

    int max_child = 0;

    for (int i = 0; i < n; i++) {
      int cur_depth = maxDepth(root->children[i]);
      max_child = max(max_child, cur_depth);
    }

    return max_child + 1;
  }
};
