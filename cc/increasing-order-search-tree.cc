// https://leetcode.com/problems/increasing-order-search-tree/description/
#include "xxx.hpp"

/**
 * Definition for a binary tree node.
 struct TreeNode {
 int val;
 TreeNode *left;
 TreeNode *right;
 TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
*/


class Solution {
public:
  TreeNode *increasingBST(TreeNode *root) {
    vector<TreeNode *> vec;
    inorder(root, vec);
    const int n = vec.size();
    for (int i = 1; i < n; ++i) {
      auto cur = vec[i - 1];
      cur->left = nullptr;
      cur->right = vec[i];
    }
    vec.back()->left = nullptr;
    return vec.front();
  }

private:
  void inorder(TreeNode *cur, vector<TreeNode *> &vec) {
    if (!cur) {
      return;
    }
    inorder(cur->left, vec);
    vec.push_back(cur);
    inorder(cur->right, vec);
  }
};

int main() {
  Solution so;
  TreeNode root(2);
  TreeNode left(1);
  TreeNode right(3);
  root.left = &left;
  root.right = &right;
  auto ret = so.increasingBST(&root);
  cout << ret->val <<endl;
}
