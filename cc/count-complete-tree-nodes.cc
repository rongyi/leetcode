// http://leetcode.com/problems/count-complete-tree-nodes/description/
#include "xxx.hpp"

class Solution {
public:
  int countNodes(TreeNode *root) {
    if (!root) {
      return 0;
    }
    // check left and right height, if they are equal
    // then the total nodes is 2 ^(h) - 1;
    TreeNode *p = root;
    int hl = 0;
    while (p) {
      hl++;
      p = p->left;
    }

    p = root;
    int hr = 0;
    while (p) {
      hr++;
      p = p->right;
    }
    if (hl == hr) {
      return (1 << hr) - 1;
    }

    return 1 + countNodes(root->left) + countNodes(root->right);
  }
};
