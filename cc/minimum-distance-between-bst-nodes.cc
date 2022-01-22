// https://leetcode.com/problems/minimum-distance-between-bst-nodes/description/
#include "xxx.hpp"

// * Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution2 {
public:
  int minDiffInBST(TreeNode *root) {
    int ret = numeric_limits<int>::max();
    int pre = -1;
    inorder(root, ret, pre);
    return ret;
  }

private:
  void inorder(TreeNode *root, int &ret, int &pre) {
    if (!root) {
      return;
    }
    inorder(root->left, ret, pre);
    if (pre != -1) {
      ret = min(ret, root->val - pre);
    }
    pre = root->val;
    inorder(root->right, ret, pre);
  }
};



class Solution {
public:
  int minDiffInBST(TreeNode *root) {
    vector<int> lst;
    inorder(root, lst);
    int ret = numeric_limits<int>::max();
    for (int i = 1; i < lst.size(); ++i) {
      ret = min(ret, lst[i] - lst[i - 1]);
    }
    return ret;
  }

private:
  void inorder(TreeNode *root, vector<int> &lst) {
    if (!root) {
      return;
    }
    inorder(root->left, lst);
    lst.push_back(root->val);
    inorder(root->right, lst);
  }
};

int main() {
  Solution so;
  TreeNode root(2), left(1), right(9);
  root.left = &left;
  root.right = &right;
  auto ret = so.minDiffInBST(&root);
  cout << ret << endl;
}
