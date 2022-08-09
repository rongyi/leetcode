// https://leetcode.com/problems/evaluate-boolean-binary-tree/
#include "xxx.hpp"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
  // a full tree, so if this node have no child, it is a leaf node
  // 0, 1 leaf, true or false
  // 2 OR
  // 3 AND
  bool evaluateTree(TreeNode *root) {
    // Every node has either 0 or 2 children. so we check left is enough
    if (root->left == nullptr) {
      return root->val;
    }
    // then it has child
    bool l = evaluateTree(root->left);
    // some shortcut
    if (root->val == 2 && l) {
      return true;
    }
    if (root->val == 3 && !l) {
      return false;
    }
    // the final value is decided by right
    // either OR case or AND case
    return  evaluateTree(root->right);
  }
};
