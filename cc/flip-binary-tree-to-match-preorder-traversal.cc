// http://leetcode.com/problems/flip-binary-tree-to-match-preorder-traversal/description/
#include "xxx.h"

class Solution {
public:
  vector<int> flipMatchVoyage(TreeNode *root, vector<int> &voyage) {
    int pos = 0;
    if (traverse(root, voyage, pos)) {
      return flips_;
    }
    return {-1};
  }

private:
  // 这个pos是个reference，所以右子树的pos会自动跟过去
  bool traverse(TreeNode *root, vector<int> &voyage, int &pos) {
    if (!root) {
      return true;
    }
    // 根节点比过了
    if (root->val != voyage[pos++]) {
      return false;
    }
    auto l = root->left;
    auto r = root->right;
    if (l != nullptr && l->val != voyage[pos]) {
      flips_.push_back(root->val);
      swap(l, r);
    }

    return traverse(l, voyage, pos) && traverse(r, voyage, pos);
  }

private:
  vector<int> flips_;
};
