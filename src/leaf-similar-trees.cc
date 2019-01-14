// https://leetcode.com/problems/leaf-similar-trees/description/
#include "xxx.h"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
  bool leafSimilar(TreeNode *root1, TreeNode *root2) {
    auto vec1 = leaf(root1);
    auto vec2 = leaf(root2);
    if (vec1.size() != vec2.size()) {
      return false;
    }

    return std::equal(vec1.begin(), vec1.end(), vec2.begin());
  }
private:
  vector<int> leaf(TreeNode *root) {
    vector<int> ret;
    inorder(root, ret);
    return ret;
  }
  void inorder(TreeNode *root, vector<int> &ret) {
    if (!root) {
      return;
    }
    inorder(root->left, ret);
    if (root->left == nullptr && root->right == nullptr) {
      ret.push_back(root->val);
    }
    inorder(root->right, ret);

  }
};
