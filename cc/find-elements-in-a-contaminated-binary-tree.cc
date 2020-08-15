// http://leetcode.com/problems/find-elements-in-a-contaminated-binary-tree/description/
#include "xxx.h"

class FindElements {
public:
  FindElements(TreeNode *root) {
    if (!root) {
      return;
    }
    root->val = 0;

    restore(root);
  }

  bool find(int target) { return values_.find(target) != values_.end(); }

private:
  void restore(TreeNode *root) {
    values_.insert(root->val);
    if (root->left) {
      root->left->val = root->val * 2 + 1;
      restore(root->left);
    }
    if (root->right) {
      root->right->val = root->val * 2 + 2;
      restore(root->right);
    }
  }

private:
  unordered_set<int> values_;
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */

int main() {
  TreeNode root(-1);
  TreeNode right(-1);
  root.right = &right;
  FindElements f(&root);
  f.find(2);
}
