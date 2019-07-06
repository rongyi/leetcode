// http://leetcode.com/problems/complete-binary-tree-inserter/description/
#include "xxx.h"

class CBTInserter {
public:
  CBTInserter(TreeNode *root) {
    root_ = root;
    q_.push(root_);
  }

  int insert(int v) {
    // 小蝌蚪找妈妈
    // 尽量找到一个空位置然后插进去
    TreeNode *mom = nullptr;
    while (!mom) {
      auto cur = q_.front();
      if (!cur->left) {
        mom = cur;
        cur->left = new TreeNode(v);
      } else if (!cur->right) {
        mom = cur;
        cur->right = new TreeNode(v);
      } else {
        q_.pop();
        q_.push(cur->left);
        q_.push(cur->right);
      }
    }

    return mom->val;
  }

  TreeNode *get_root() { return root_; }

private:
  TreeNode *root_;
  queue<TreeNode *> q_;
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(v);
 * TreeNode* param_2 = obj->get_root();
 */
