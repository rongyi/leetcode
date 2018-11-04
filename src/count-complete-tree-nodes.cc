// http://leetcode.com/problems/count-complete-tree-nodes/description/
#include "simpleone.h"

class Solution {
public:
  int countNodes(TreeNode *root) {
    if (!root) {
      return 0;
    }
    int hl = 0;
    int hr = 0;

    TreeNode *pl = root;
    while (pl) {
      hl++;
      pl = pl->left;
    }

    TreeNode *pr = root;
    while (pr) {
      hr++;
      pr = pr->right;
    }
    // perfect tree
    if (hl == hr) {
      return pow(2, hl) - 1;
    }
    return 1 + countNodes(root->left) + countNodes(root->right);
  }
};
